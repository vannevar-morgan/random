function [ unique_y ] = calc_unique_y( r_values )
%CALC_UNIQUE_Y Summary of this function goes here
%   Detailed explanation goes here

    unique_y = [];
    
    r_values = r_values - 0.001;
    for t = 1:length(r_values)
        
        r = r_values(t);
        bifurcations = [];
        bif_count = 0;
        p = [];
        p(1) = 0.5;
        
        % Calculate P-values
        iterations = 2048;
        for i = 2:iterations
            p(i) = r*p(i-1)*(1 - p(i-1));
        end

        % I'm taking the last 512 elements of the calculate P-values.
        for i = 1:512
            trim_values(i) = p(length(p) - (1024-i));
        end

        % Find the unique values of p for each r, and append to unique_y        
        period_type = 2^(t);
        for j = 1:period_type
            unique_y = [unique_y, trim_values(j)];
        end
        
    end

end

