% vann
% Finding Feigenbaum Delta and Alpha constants
% 02/25/2011

function [ does_it_split ] = is_bifurcation( p, known_bifs )
%IS_BIFURCATION checks to see if a given set P is a bifurcation point.  It
%does this by comparing the values of P and judging the behavior that it
%exhibits (2-Period, 4-Period, etc.).  If the behavior has not been
%observed previously, then the point, r, for which P was calculated, is
%judged to be a bifurcation point.

    does_it_split = 0;
    period_type = 0;
    
    trim_values = [];
    for i = 1:1024
        trim_values(i) = p(length(p) - (1024-i));
        % I'm taking the last 1024 elements, this means I can compare for up
        % to 2^9 elements, 512 period?
    end
    
    known_bifs = known_bifs + 1; % I'm looking for the next bifurcation, I know there are known_bifs already so I need to look for known_bifs + 1.
    period_type = 2^known_bifs;
    
    for i = 1:period_type
        if ~nearly_equal(trim_values(i), trim_values(i + period_type))
            % This is checking to see if a period type is exhibited.  i.e.
            % a 2-period type should have equal 1-3, 2-4.  a 4-period type
            % should have equal 1-5, 2-6, 3-7, 4-8.
            
            %disp 'not alike'
            %i
            break;
        end
        does_it_split = 1;
    end
    
    for i = 1:period_type-1
        if nearly_equal(trim_values(1), trim_values(i + 1))
            % This is checking to make sure that the period type has not
            % been seen before.  In the main program, I count every time a
            % bifurcation is found and return to this function the number
            % of known bifurcations.  So if I'm looking for a 4-period, I
            % need to know I'm not observing a 2-period.  i.e. a 4-period
            % should have NOT equal, 1-2,3,4.
            
            %disp 'too alike'
            does_it_split = 0;
            break;
        end    
    end
    
end

