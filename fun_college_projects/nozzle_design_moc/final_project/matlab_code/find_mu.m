function [ mu ] = find_mu( mach )
%This function finds the mach angle, mu in degrees, given the mach number

mu = asind(1/mach);

end

