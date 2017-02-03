% vann
% Finding Feigenbaum Delta and Alpha constants
% 02/25/2011

function [ alphas ] = calc_alphas( superstables )
%CALC_ALPHAS calculates the alpha constant given a set of superstable
%points.

    alphas = [];
    
    for i = 1:length(superstables) - 1
        if isequal(superstables(i + 1), 0)
            break;
        end
        alphas(i) = superstables(i)/superstables(i+1);
    end

end

