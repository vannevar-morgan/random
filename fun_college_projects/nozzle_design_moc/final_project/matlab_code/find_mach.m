function [ mach ] = find_mach( gamma, v )
%Finds and returns the Mach number (to practicality, it's iterative and will only search from Mach 1 through Mach 50)
%given the values of gamma and the Prandtl-Meyer function, v in degrees
%   If it fails to loacte the Mach number then it returns Mach = 0
mach = 0;
for i = 1 : 0.01 : 50
    prandtl = find_prandtl_meyer(gamma, i);
    if prandtl > (v - 0.17) && prandtl < (v + 0.17)
        mach = i;
        break;
    end
end

end

