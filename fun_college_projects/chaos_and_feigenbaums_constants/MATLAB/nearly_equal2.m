% vann
% Finding Feigenbaum Delta and Alpha constants
% 02/25/2011

function [ are_they_equal ] = nearly_equal2( a, b )
%NEARLY_EQUAL2 checks to see if two numbers are equal within some tolerance
%value.  NEARLY_EQUAL2 is distinct from NEARLY_EQUAL only because the
%tolerance needs to be less when searching for superstable points orelse
%I'm not able to catch the correct superstable point (The tolerance of
%NEARLY_EQUAL is too strict).

    are_they_equal = 0;
    if abs(a-b) < 0.0005
        are_they_equal = 1;
    end
    
end

