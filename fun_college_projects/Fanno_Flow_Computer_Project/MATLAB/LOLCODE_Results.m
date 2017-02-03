% vann
% Experimental Aero, Lab 1

clear all;
clc;
datasets = inputdlg('Enter number of data files to process', 'Process Data Files', 1);
datasets = str2num(datasets{1});

test_data = cell(1,1);
for i = 1:datasets
    test_data{i,1} = Lab1_DataReader; % This is reading the data in from text file versions of the excel spreadsheet
end
%%
% This is extracting the individual data sets for each case from the cell.
mach_03 = test_data{1,1};

%%
% Now I need to extract the actual data that I need to plot from each
% matrix.

increment = mach_03(:,1);
machs = mach_03(:,2);
total_pressure_ratio = mach_03(:,3);
static_temp_ratio = mach_03(:,4);
static_pressure_ratio = mach_03(:,5);

%%
plot(increment, total_pressure_ratio, 'r', increment, machs, 'b', increment, static_pressure_ratio, 'g', increment, static_temp_ratio, 'k');
xlabel('Axial Position in burner (Inches)');
ylabel('Computed Ratios');
title('Computed ratios, Total Temperature, Mach #, etc. as a function of Burner Length, with Inlet Mach # = 0.30');
grid on;
legend('Total Pressure Ratio', 'Mach #', 'Static Pressure Ratio', 'Static Temperature Ratio')
