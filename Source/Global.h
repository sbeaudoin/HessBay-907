#pragma once

#include <Arduino.h>

/*
	Define the firmware version.
*/
const String VERSION = "1.0.0";

/*
	Un comment the line to activate the test mode.
*/
//#define TEST_MODE

/*
	Pin constants.
*/
const int PIN_ENCODER_A = 2;
const int PIN_ENCODER_B = 3;
const int PIN_BUZZER = 13;

/*
	Different constants who will go to the eprom.
*/

enum TempUnits { Celcius, Fahrenheit };

const int SLEEP_TEMP = 100;
const int PROFILE_A_TEMP = 150;
const int PROFILE_B_TEMP = 200;
const int PROFILE_C_TEMP = 0;
const int SLEEP_DELAY_SECONDS = 30;
const int AUTO_OFF_DELAY_SECONDS = 60;
const TempUnits TEMPERATURE_UNITS = TempUnits::Celcius;
const int LAST_TARGET_TEMP = 0;

/*
	Declare the name of each page used in the navigator as an enumeration value.  On the initialisation of the Navigator class, 
	use a template value S equals to the number of pages.
*/
enum PageName
{
	NoPage,

	/*
		Main page who shows the different profiles and the current soldering iron temperature.
	*/
	Main,

	/*
		Configuration page of the application.
	*/
	Configuration
};

/*
Temperature profile selection.
*/
enum ProfileName
{
	/*
	No profile selected.
	*/
	NoProfile,

	/*
	Profile A is selected.
	*/
	ProfileA,

	/*
	Profile B is selected.
	*/
	ProfileB,

	/*
	Profile C is selected.
	*/
	ProfileC
};


