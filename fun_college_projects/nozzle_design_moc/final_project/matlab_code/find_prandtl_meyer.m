function [ v ] = find_prandtl_meyer( gamma, mach )
%Finds and returns the Prandtl-Meyer function, v in degrees, given the values of gamma and the Mach
%number

a = (gamma + 1)/(gamma - 1);
v = ((a)^.5 * atand(((1/a)*((mach^2) - 1))^.5)) - atand(((mach^2) - 1)^.5);

end

