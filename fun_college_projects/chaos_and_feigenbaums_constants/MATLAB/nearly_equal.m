% vann
% Finding Feigenbaum Delta and Alpha constants
% 02/25/2011

function [ are_they_equal ] = nearly_equal( a, b )
%NEARLY_EQUAL checks to see if two numbers are equal within some tolerance
%value.

    are_they_equal = 0;
    if abs(a-b) < 0.0001
        are_they_equal = 1;
    end
    
end

