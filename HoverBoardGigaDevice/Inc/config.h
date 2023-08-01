

#ifndef CONFIG_H
#define CONFIG_H

#include "gd32f1x0.h"

// ################################################################################
// select one of the supported circuit boards and whether to compile the slave- or master board
// only the master has a buzzer :-)

// LAYOUT_2_X is used in defines.h
#define LAYOUT_2_0	// https://github.com/flo199213/Hoverboard-Firmware-Hack-Gen2
//#define LAYOUT_2_1	// https://github.com/krisstakos/Hoverboard-Firmware-Hack-Gen2.1
//#define LAYOUT_2_2	// 2023/05/11 only MASTER and TEST_SPEED: motor is spinning but needs a push to startup :-/
//#define LAYOUT_2_4	// NOT READY !!! https://github.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/issues/3


//#define MASTER		// uncomment if firmware is for slave board

//#define TEST_SPEED	// will discard uart input and repeat speed from -300 to 300 instead

#ifdef MASTER
	#define SPEED_COEFFICIENT   -1
	#define STEER_COEFFICIENT   1
#else
	#define SLAVE 												// Select if firmware is for master or slave board
#endif


// ################################################################################

#define PWM_FREQ         		16000     // PWM frequency in Hz
#define DEAD_TIME        		60        // PWM deadtime (60 = 1�s, measured by oscilloscope)

#define DC_CUR_LIMIT     		15        // Motor DC current limit in amps

#define BAT_CELLS         		24/3.7  	//normally number of 3.7v battery cells, but modified to support 24v (2 12v lead-acid in series)

//#define BLDC_WEAKENING		// some kind of field weaking added by HarleyBob for his gen2.2 firmware ?

// ################################################################################

#define DELAY_IN_MAIN_LOOP 	5         // Delay in ms

#define TIMEOUT_MS          2000      // Time in milliseconds without steering commands before pwm emergency off

#ifdef MASTER
	#define INACTIVITY_TIMEOUT 	8        	// Minutes of not driving until poweroff (not very precise)

	// ################################################################################


	#define CELL_LOW_LVL1     3.5       // Gently beeps, show green battery symbol above this Level.
	#define CELL_LOW_LVL2     3.3       // Battery almost empty, show orange battery symbol above this Level. Charge now! 
	#define CELL_LOW_DEAD     3.1       // Undervoltage lockout, show red battery symbol above this Level.

	#define BAT_LOW_LVL1     BAT_CELLS * CELL_LOW_LVL1
	#define BAT_LOW_LVL2     BAT_CELLS * CELL_LOW_LVL2
	#define BAT_LOW_DEAD     BAT_CELLS * CELL_LOW_DEAD

	/*
	#define BAT_LOW_LVL1     35.0       // Gently beeps, show green battery symbol above this Level.
	#define BAT_LOW_LVL2     33.0       // Battery almost empty, show orange battery symbol above this Level. Charge now! 
	#define BAT_LOW_DEAD     31.0       // Undervoltage lockout, show red battery symbol above this Level.
	// ONLY DEBUG-LEVEL!!!
	//#define BAT_LOW_LVL1     29.0
	//#define BAT_LOW_LVL2     28.0
	//#define BAT_LOW_DEAD     27.0
	*/

	// ################################################################################
#endif

// ###### ARMCHAIR ######
#define FILTER_SHIFT 12 						// Low-pass filter for pwm, rank k=12


#endif
