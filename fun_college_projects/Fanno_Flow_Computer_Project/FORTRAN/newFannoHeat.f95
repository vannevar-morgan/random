PROGRAM newFannoHeat
!	NAME:  vann
!	Air Breathing Computer Project
!	03/17/2011


	REAL :: mach_1 = 0.0	!	inlet Mach number
	REAL :: p_01 = 300		!	inlet total pressure, psia
	REAL :: l_star = 18		!	characteristic length, inches
	REAL :: d = 5		!	burner diameter, inches
	REAL :: f = 0.04		!	friction factor
	REAL :: t_01 = 1200		!	inlet total temperature
	REAL :: t_02 = 2400		!	exit total temperature
	REAL :: gamma = 1.30	!	ratio of specific heats
	REAL :: increments = 100	!	The number of increments of the burner

	INTEGER j				!	Loop increment variable
	INTEGER i				!	Loop increment variable

	!	Filenames for the data to output to.
	CHARACTER(32) :: file1 = 'mach0.00.txt'
	CHARACTER(32) :: file2 = 'mach0.05.txt'
	CHARACTER(32) :: file3 = 'mach0.10.txt'
	CHARACTER(32) :: file4 = 'mach0.15.txt'
	CHARACTER(32) :: file5 = 'mach0.20.txt'
	CHARACTER(32) :: file6 = 'mach0.25.txt'
	CHARACTER(32) :: file7 = 'mach0.30.txt'
	CHARACTER(32) :: file8 = 'mach0.35.txt'
	CHARACTER(32) :: file9 = 'mach0.40.txt'
	CHARACTER(32), DIMENSION(9) :: files
	
	REAL del_l		 		!	The constant delta-L increment
	REAL del_t				!	The constant delta_t0 increment
	REAL ct1					!	The first common term (explained in attached work), factored out -- it makes the programming easier
	REAL ct2					!	The second common term (explained in attached work), factored out -- it makes the programming easier
	REAL ct3					!	The third common term (explained in attached work), factored out -- it makes the programming easier
	REAL temp_comp				!	The temperature component, factored out
	REAL frict_comp				!	The friction component, factored out

	REAL p_02				!	The total pressure at a station position
	REAL p_02_temp
	REAL mach_2				!	The exit Mach number at a station position
	REAL mach_2_temp
	REAL t_1					!	The inlet static temperature
	REAL t_2					!	The static temperature at a station position
	REAL t_2_temp
	REAL p_1					!	The inlet static pressure
	REAL p_2					!	The static pressure at a station position
	REAL p_2_temp

	REAL t_01_temp

	
	files = (/file1, file2, file3, file4, file5, file6, file7, file8, file9/)


	DO j = 1, 9
		!mach_1 = mach_1 + 0.05
		del_l = l_star / increments
		del_t = (t_02 - t_01) / increments

		temp_comp = del_t / t_01
		frict_comp = (4*f*del_l) / d			!	frict_comp is constant
		t_1 = t_01 / (1 + (gamma - 1)*0.5*(mach_1**2))
		p_1 = p_01 / ((1 + (gamma - 1)*0.5*(mach_1**2))**(gamma/(gamma - 1)))
				
		p_02_temp = p_01
		mach_2_temp = mach_1
		t_2_temp = t_1
		p_2_temp = p_1
		t_01_temp = t_01
	
		OPEN(UNIT = 1, FILE = TRIM(files(j)), IOSTAT = ierror)
			777 FORMAT(1X, I3, T9, F6.3, T24, F6.3, T39, F6.3, T54, F6.3 )

			!	These are the initial values at the inlet.
			WRITE(1, 777) 0, mach_1, p_01/p_01, t_1/t_1, p_1/p_1
			
			
			DO i = 1, 100	!	Inside the loop I am calculating the values for each position after the inlet.
		
				ct1 = (1 + ((gamma - 1)/2) * (mach_2_temp**2)) / (1 - (mach_2_temp**2))
				ct2 = -1*gamma*(mach_2_temp**2)
				ct3 = 2*(1 - (mach_2_temp**2))
		
				!	Calculating the total pressure
				p_02 = p_02_temp + p_02_temp * (ct2/2)*(temp_comp + frict_comp)
				p_02_temp = p_02
				
				!	Calculating the static temperature
				t_2 = t_2_temp + t_2_temp * ((1 + ct2)*ct1*temp_comp + (ct2/ct3)*(gamma - 1)*(mach_2_temp**2)*frict_comp)
				t_2_temp = t_2
				
				!	Calculating the static pressure
				p_2 = p_2_temp + p_2_temp * ct2 * ((ct1)*temp_comp + (1 + (gamma - 1)*(mach_2_temp**2))*(frict_comp/ct3))
				p_2_temp = p_2
				
				!	Calculating the Mach number
				mach_2 = mach_2_temp**2 + (mach_2_temp**2) * ct1 * ((1-ct2)*(temp_comp) - (ct2*frict_comp))
				mach_2 = mach_2**0.5
				mach_2_temp = mach_2
		
				t_01_temp = t_01_temp + del_t
				temp_comp = del_t / t_01_temp
				
				WRITE(1, 777) i, mach_2, p_02/p_01, t_2/t_1, p_2/p_1
				
			END DO
	
		CLOSE(1)
		mach_1 = mach_1 + 0.05
	
	END DO

END PROGRAM newFannoHeat


