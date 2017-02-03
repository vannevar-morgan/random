%%
%vann
%Nozzle Design Term Project - Design of minimum length 2-D Nozzle by
%Method Of Characteristics
%%
clear all
clc

num_char_lines = 30;
gamma = 1.22;
%This is not the actual gamma or mach @ exit, we still need to find this
mach_exit = 2.46;
noz_char_matrix = [];

%Find the total corner angle, theta_w_max
theta_w_max = find_prandtl_meyer(gamma, mach_exit)/2;

%This is creating the values as column vectors for the initial
%characteristic lines
theta_initial = (linspace(0.01, theta_w_max, num_char_lines)');
v_initial = theta_initial;
k_plus_initial = theta_initial - v_initial;
k_minus_initial = theta_initial + v_initial;

%%
%This is creating the values as column vectors for the remaining (i.e. not
%the initial ones) characteristic lines
k_plus = [];
k_minus = [];
thetas = [];
stepAngle = theta_initial(2,1) - theta_initial(1,1);
[m,n] = size(k_minus_initial);

for a = 2:m
    %This first loop is running through each of the points, starting at the
    %second point
    for b = 1:((m+1)-a)
        %This loop is decreasing the number of times (by 1) that the first
        %loop runs through the point.  The entire loop is appending
        %k_plus at each point(loop 1) by the number of times for that point (loop 2)
        %It's also doing the same thing for the thetas
        k_plus = [k_plus; (-1 * (k_minus_initial(a, 1)))];
        thetas = [thetas; (b-1)*stepAngle];
    end
    %This is simply appending the last element twice for the specific point
    k_plus = [k_plus; (-1 * (k_minus_initial(a, 1)))];
    thetas = [thetas; (b-1)*stepAngle];
end
%%
k_minus = 2.*thetas - k_plus;
prandtl_v = (k_plus.*-1) + (thetas);

%Repeating the last elements in the initial characteristic column vectors.
[m,n] = size(theta_initial);
theta_initial = [theta_initial; theta_initial(m, 1)];
v_initial = [v_initial; v_initial(m, 1)];
k_plus_initial = [k_plus_initial; k_plus_initial(m, 1)];
k_minus_initial = [k_minus_initial; k_minus_initial(m, 1)];

%Appending the secondary characteristic vectors to the initial
%characteristic vectors

[m,n] = size(thetas);
noz_points = ((1:(m+1+num_char_lines))');
noz_k_minus = [k_minus_initial; k_minus];
noz_k_plus = [k_plus_initial; k_plus];
noz_thetas = [theta_initial; thetas];
noz_prandtl_v = [v_initial; prandtl_v];
[noz_machs, noz_mus] = find_machs_and_mus(gamma, noz_prandtl_v);

noz_char_matrix = [noz_char_matrix noz_points noz_k_minus noz_k_plus noz_thetas noz_prandtl_v noz_machs noz_mus]


%This is counting up the number of total characteristic lines, not just the
%initial lines, num_char_lines.

total_lines = 0;
for a = (num_char_lines + 1):-1:2
    total_lines = total_lines + a;
end

%This is making matrices of the slopes for the theta lines and the left
%characteristic lines
slopes_theta = [];
slopes_theta = [slopes_theta; theta_w_max];
char_slopes_left = [];

        %This is extracting the theta values from the theta matrix.  It is
        %also computing the angles of the left characteristic lines using
        %angle = theta + mu
a = (num_char_lines + 1);
b = num_char_lines;
while a <= total_lines
    slopes_theta = [slopes_theta; noz_thetas(a, 1)];
    char_slopes_left = [char_slopes_left; noz_thetas(a, 1) + noz_mus(a, 1)];
    a = a + b;
    b = b - 1;
end

        %This is computing the characteristic slopes for the theta lines
        %(lines along the contour) as an average of the theta values 
        %previously extracted
char_slopes_theta = [];

for a = 1:num_char_lines
    theta_avg = (0.5)*(slopes_theta(a,1) + slopes_theta(a+1,1));
    char_slopes_theta = [char_slopes_theta; theta_avg];
end

        %This here is actually creating the slope matrices.  Previously the 
        %matrices contained values representing angles from +x axis
char_slopes_theta = tand(char_slopes_theta);
char_slopes_left = tand(char_slopes_left);



%This is finding the x and y coordinates of points of interest (points
%where characteristic lines intercept) along the nozzle contour.  These
%points will then be plotted to produce the nozzle contour.
points_x = [];
points_y = [];
left_y_int = -1;
right_y_int = 1;

points_x = [points_x; 0];
points_y = [points_y; 1];

for a = 1:num_char_lines
    
    x = (right_y_int - left_y_int)/(char_slopes_left(a,1) - char_slopes_theta(a,1));
    y = (char_slopes_theta(a,1)*x) + right_y_int;
    points_x = [points_x; x];
    points_y = [points_y; y];
    if a < num_char_lines
        right_y_int = y - (char_slopes_theta(a+1,1)*x);
    end
end



%This is plotting the nozzle contour
plot(points_x, points_y, points_x, -1.*points_y)
axis('equal');



%points_y
%points_x






