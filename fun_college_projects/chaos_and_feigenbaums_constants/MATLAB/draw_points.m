function [  ] = draw_points( x, y )
%DRAW_POINTS Plots points on the Bifucation Diagram.

    for i = 1:length(x) - 3
        plot(x,y,'ro')
        hold on;
    end
    plot(x(127),y(127),'bo')
    plot(x(128),y(128),'bo')
    plot(x(129),y(129),'bo')
    refline(0, 0.5);
    
    xlabel('Lamdas');
    ylabel('P');
    title('Bifurcation Diagram');
end

