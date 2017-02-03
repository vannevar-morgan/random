function [ x, y ] = assemble_xy(bifurcations)
%ASSEMBLE_XY Summary of this function goes here
%   Detailed explanation goes here
    x = [];
    y = [];
    x_count = 0;
    
    for i = 1:length(bifurcations)
        period_type = 2^i;
        for j = 1:period_type
            x_count = x_count + 1;
            x(x_count) = bifurcations(i);
        end
    end

    y = calc_unique_y(bifurcations);

end

