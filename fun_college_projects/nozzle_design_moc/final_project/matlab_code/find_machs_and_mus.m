function [ machs, mus ] = find_machs_and_mus( gamma, v_column )
%Creates the columns of machs and mus given the value of gamma and the 
%column of Prandtl-Meyer values, v
%   Returns two column vectors of size equal to the size of the
%   Prandtl-Meyer matrix, v, provided as input

[m,n] = size(v_column);
machs = [];
mus = [];
for i = 1:m
    machs = [machs; find_mach(gamma, v_column(i,1)) ];
end
for i = 1:m
    mus = [mus; find_mu(machs(i,1)) ];
end

end

