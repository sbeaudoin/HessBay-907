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


