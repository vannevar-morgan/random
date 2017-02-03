% vann
% Finding Feigenbaum Delta and Alpha constants
% 02/25/2011

function [ dels ] = calc_dels( bifurcations )
%CALC_DELS calculates the delta constant given a set of bifuraction points.

    dels = [];
    
    for i = 1:length(bifurcations) - 2
        dels(i) = (bifurcations(i+1) - bifurcations(i))/(bifurcations(i+2) - bifurcations(i+1));
    end

end

