#pragma once

#include "Global.h"
#include <TFT_HX8357.h>
#include <Arduino.h>
#include "EncoderDriver.h"

/*
	Base virtual class for all pages.
*/
class PageBase
{

public :

	/*
		Initialize a new instance.

		IN
		--
		*lcdDriver : Pointer to the LCD driver instance.
	*/
	PageBase(TFT_HX8357 *lcdDriver, EncoderDriver *encoderDriver) 
	{
		LCD = lcdDriver;
		Encoder = encoderDriver;
	}

	/*
		Initialise the page.
	*/
	virtual void Setup() = 0;

	/*
		Loop execution of the page.  The page code can exit the loop and specify the next page who should be displayed and
		executed.

		OUT
		---
		The next page who should be displayed.
	*/
	virtual PageName Loop() = 0;

	virtual void HandleEncoderChange() = 0;

protected :

	/*
		The LCD driver instance.
	*/
	TFT_HX8357 *LCD;

	EncoderDriver *Encoder;
};
