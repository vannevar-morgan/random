% vann
% Experimental Aero, Lab 1
% This reads in data from a text file
function [data_from_file] = Lab1_DataReader()
    my_file_home = pwd;
    cd('C:\Users\vann\Desktop\');
    [datafile, datapath] = uigetfile('*.txt', 'Select Data Text File');
    cd(datapath);
    data_from_file = dlmread(datafile);
    cd(my_file_home);
end
