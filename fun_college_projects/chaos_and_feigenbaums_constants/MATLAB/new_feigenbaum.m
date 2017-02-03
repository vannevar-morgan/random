% vann
% Finding Feigenbaum Delta and Alpha constants
% 02/25/2011

clear all;
clc;

bifurcations = [];
bif_count = 0;
p = [];
p(1) = 0.5;
superstables = [];
superstables_count = 0;
superstables_r = [];
for r = 3:0.001:3.65
    
    % Calculate P-values
    iterations = 2048;
    for i = 2:iterations
        p(i) = r*p(i-1)*(1 - p(i-1));
    end
    
    % Find the bifurcation points in order to calculate delta.
    if(is_bifurcation(p, bif_count))
        bif_count = bif_count + 1;
        bifurcations(bif_count) = r;
    end
    r
    
    % I'm taking the last 512 elements of the calculate P-values.
    for i = 1:512
        trim_values(i) = p(length(p) - (1024-i));
    end
    
    % Find the superstable positions in order to calculate alpha.
    if superstables_count < bif_count
        for i = 1:512
            if nearly_equal2(0.5, trim_values(i))
                superstables_count = superstables_count + 1;
                period_type = 2^(bif_count);
                unique_period_values = [];
                for j = 1:period_type
                    unique_period_values(j) = abs(trim_values(j) - 0.5);
                end
                unique_period_values(i) = 999; % This is the bifurcating point equal to 0.5.  I need to 
                                               % ignore it so I set it high so it won't ever be noticed by min().
                superstables(superstables_count) = min(unique_period_values);
                superstables_r(superstables_count) = r;
                break;
            end
        end
    end
    
end
disp 'Calculated Deltas';
calc_dels(bifurcations)
disp 'Calculated Alphas';
calc_alphas(superstables)



