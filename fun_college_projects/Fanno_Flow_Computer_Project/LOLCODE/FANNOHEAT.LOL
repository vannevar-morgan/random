OBTW
	vann
	03/17/2011
	AirBreathing Computer Project
	Combined Fanno Flow and Heat Addition through Burner.
	LOLCODE compiler available at http://www.microngamestudios.com/lolexec.html
TLDR

HOW DUZ I EXPONENTIATE YR BASE YR POWER
        BTW        This function performs exponentiation.  Apparently LOLCODE does not have a built in power (^) operator, so here I perform a Taylor series to 42 terms in order to approximate x^n.
        I HAS A COUNTER2 ITZ 0
        I HAS A FACTORIAL ITZ 1.0
        I HAS A ANSWER ITZ 1.0
        I HAS A TAYLOR ITZ 1.0

        IM IN YR LOOP UPPIN YR COUNTER2

                FACTORIAL R PRODUKT OF FACTORIAL AN SUM OF COUNTER2 AN 1.0
                
                TAYLOR R PRODUKT OF TAYLOR AN PRODUKT OF DIFF OF BASE AN 1 AN DIFF OF POWER AN COUNTER2
BTW                VISIBLE QUOSHUNT OF TAYLOR AN FACTORIAL
                ANSWER R SUM OF ANSWER AN QUOSHUNT OF TAYLOR AN FACTORIAL

                BOTH SAEM COUNTER2 AN 42, O RLY?
                        YA RLY
                                GTFO
                OIC

        IM OUTTA YR LOOP

        FOUND YR ANSWER

IF U SAY SO



HAI 1.2

        CAN HAS STDIO?
        I HAS A MACH_1 ITZ 0.3        BTW        This is the inlet mach number
        I HAS A P_01 ITZ 300.0        BTW        This is the inlet total pressure (psia)
        I HAS A L_STAR ITZ 18.0        BTW        This is the characteristic length (inches)
        I HAS A D ITZ 5.0        BTW        This is the burner diameter (inches)
        I HAS A F ITZ 0.040        BTW        This is the friction factor
        I HAS A T_01 ITZ 1200.0        BTW        This is the inlet total temperature (Rankine)
        I HAS A T_02 ITZ 2400.0        BTW        This is the outlet total temperature (Rankine)
        I HAS A GAMMA ITZ 1.30        BTW        This is the ratio of specific heats (assumed constant)

        I HAS A DEL_L ITZ 0.0        BTW        This will be a axial position variable
        I HAS A DEL_T ITZ 0.0        BTW        This will be a temperature difference variable
        I HAS A COUNTER ITZ 1
        I HAS A VAR

        I HAS A P_02 ITZ 0.0
        I HAS A P_02_TEMP ITZ 0.0
        I HAS A T_1 ITZ 0.0
        I HAS A T_2 ITZ 0.0
        I HAS A T_2_TEMP ITZ 0.0
        I HAS A P_1 ITZ 0.0
        I HAS A P_2 ITZ 0.0
        I HAS A P_2_TEMP ITZ 0.0
        I HAS A MACH_2_SQUARED ITZ 0.0
        I HAS A MACH_2_SQUARED_TEMP ITZ 0.0
        I HAS A MACH_2 ITZ 0.0
        I HAS A FRICT_COMP ITZ 0.0
        I HAS A TEMP_COMP ITZ 0.0
        I HAS A CT1 ITZ 0.0
        I HAS A CT2 ITZ 0.0
        I HAS A CT3 ITZ 0.0
        I HAS A T_01_TEMP ITZ 0.0

        T_1 R QUOSHUNT OF T_01 AN SUM OF 1 AN PRODUKT OF 0.5 AN PRODUKT OF DIFF OF GAMMA AN 1 AN PRODUKT OF MACH_1 AN MACH_1
        P_1 R SUM OF 1 AN PRODUKT OF 0.5 AN PRODUKT OF DIFF OF GAMMA AN 1 AN PRODUKT OF MACH_1 AN MACH_1
        P_1 R EXPONENTIATE P_1 QUOSHUNT OF GAMMA AN DIFF OF GAMMA AN 1
        P_1 R QUOSHUNT OF P_01 AN P_1

        P_02_TEMP R P_01
        MACH_2_SQUARED_TEMP R PRODUKT OF MACH_1 AN MACH_1
        T_2_TEMP R T_1
        P_2_TEMP R P_1
        T_01_TEMP R T_01

        VISIBLE SMOOSH 0 AN " " AN MACH_1 AN " " AN QUOSHUNT OF P_01 AN P_01 AN " " AN QUOSHUNT OF T_1 AN T_1 AN " " AN QUOSHUNT OF P_1 AN P_1 MKAY
        IM IN YR LOOP UPPIN YR COUNTER
                BTW        DEL_L R SUM OF DEL_L AN QUOSHUNT OF L_STAR AN 100.0
                BTW        DEL_T R SUM OF DEL_T AN 2.0

                DEL_L R QUOSHUNT OF L_STAR AN 100.0
                DEL_T R QUOSHUNT OF DIFF OF T_02 AN T_01 AN 100.0

                FRICT_COMP R PRODUKT OF PRODUKT OF 4 AN F AN QUOSHUNT OF DEL_L AN D
                T_01_TEMP R SUM OF T_01_TEMP AN DEL_T
                TEMP_COMP R QUOSHUNT OF DEL_T AN T_01_TEMP

                BTW Computing value of P_02 for the current location, temperature step in the burner                
                P_02 R SUM OF P_02_TEMP AN PRODUKT OF PRODUKT OF P_02_TEMP AN PRODUKT OF MACH_2_SQUARED_TEMP AN PRODUKT OF GAMMA AN -0.5 AN SUM OF TEMP_COMP AN FRICT_COMP
                P_02_TEMP R P_02


                BTW Factored out common terms from equations and computing separately for ease of coding
                CT1 R QUOSHUNT OF SUM OF 1 AN PRODUKT OF 0.5 AN PRODUKT OF DIFF OF GAMMA AN 1 AN MACH_2_SQUARED_TEMP AN DIFF OF 1 AN MACH_2_SQUARED_TEMP
                CT2 R PRODUKT OF -1 AN PRODUKT OF GAMMA AN MACH_2_SQUARED_TEMP
                CT3 R PRODUKT OF 2 AN DIFF OF 1 AN MACH_2_SQUARED_TEMP                

                BTW Computing value of T_2 for the current location, temperature step in the burner
                T_2 R SUM OF T_2_TEMP AN PRODUKT OF T_2_TEMP AN SUM OF PRODUKT OF PRODUKT OF TEMP_COMP AN CT1 AN SUM OF 1 AN CT2 AN PRODUKT OF QUOSHUNT OF CT2 AN CT3 AN PRODUKT OF MACH_2_SQUARED_TEMP AN PRODUKT OF FRICT_COMP AN DIFF OF GAMMA AN 1
                T_2_TEMP R T_2


                BTW Computing value of P_2 for the current location, temperature step in the burner
                P_2 R SUM OF P_2_TEMP AN PRODUKT OF PRODUKT OF P_2_TEMP AN CT2 AN SUM OF PRODUKT OF CT1 AN TEMP_COMP AN QUOSHUNT OF PRODUKT OF FRICT_COMP AN SUM OF 1 AN PRODUKT OF DIFF OF GAMMA AN 1 AN MACH_2_SQUARED_TEMP AN CT3
                P_2_TEMP R P_2

                BTW Computing value of MACH_2_SQUARED
                MACH_2_SQUARED R SUM OF MACH_2_SQUARED_TEMP AN PRODUKT OF MACH_2_SQUARED_TEMP AN PRODUKT OF CT1 AN SUM OF PRODUKT OF TEMP_COMP AN DIFF OF 1 AN CT2 AN PRODUKT OF FRICT_COMP AN DIFF OF 0 AN CT2

                MACH_2_SQUARED_TEMP R MACH_2_SQUARED
                MACH_2 R EXPONENTIATE MACH_2_SQUARED 0.5



BTW                GIMMEH VAR
                VISIBLE SMOOSH PRODUKT OF L_STAR AN PRODUKT OF 0.01 AN SUM OF 1 AN COUNTER AN " " AN MACH_2 AN " " AN QUOSHUNT OF P_02 AN P_01 AN " " AN  QUOSHUNT OF T_2 AN T_1 AN " " AN QUOSHUNT OF P_2 AN P_1 MKAY

                
                BOTH SAEM COUNTER AN 99, O RLY?        BTW        Loop counter goes 0 - 99, means 100 intervals
                        YA RLY
                                BTW I'm breaking out of the loop here because I've now computed through the entire length of the burner
                                GTFO
                 OIC
        IM OUTTA YR LOOP


BTW        VISIBLE SMOOSH "Length Increment" AN "        " AN "Ratio of Total Pressures" AN "        " AN "Ratio of Mach 2 / 1" AN "        " AN "Ratio of Static Temperatures" AN "        " AN "Ratio of Static Pressures" AN "        " AN "Mach 2 Squared" AN "        " AN "Static Temperature 2" AN "        " AN "Static Pressure 2" AN "        " AN "Mach 2"        MKAY


KTHXBYE




