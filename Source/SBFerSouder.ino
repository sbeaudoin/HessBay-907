#include <TimerOne.h>
#include "TFT_HX8357.h"
#include "PageBase.h"
#include "MainPage.h"
#include "ConfigurationPage.h"
#include "PageEntry.h"
#include "Navigator.h"
#include "TempControlService.h"

/*
	Initialize the services.
*/
TempControlService _tempSvc = TempControlService();

/*
	Initialize the drivers.
*/
TFT_HX8357 _lcdDriver = TFT_HX8357(480, 320);
EncoderDriver _encoderDriver = EncoderDriver(PIN_ENCODER_A, PIN_ENCODER_B, true);

/*
	Initialize the pages used in the sketch.
*/
MainPage _mainPage = MainPage(&_lcdDriver, &_encoderDriver, &_tempSvc);
ConfigurationPage _configPage = ConfigurationPage(&_lcdDriver, &_encoderDriver, &_tempSvc);

/*
	Associate the page with a static name and put this in a PageEntry.
*/
PageEntry _mainPageEntry = PageEntry(PageName::Main, &_mainPage);
PageEntry _configPageEntry = PageEntry(PageName::Configuration, &_configPage);

/*
	Initialize the navigator.
*/
PageEntry _entries [] = { _mainPageEntry };
Navigator<1> _navigator = Navigator<1>(_entries);

int _test = 0;

void setup() 
{
	Serial.begin(9600);
	Serial.println("--START--");
	pinMode(PIN_BUZZER, OUTPUT);

	// Initialize the LCD driver.
	_lcdDriver.begin();
	_lcdDriver.setRotation(3); // As I use a ILI9481, I must set my screen upside/down.
	_lcdDriver.fillScreen(TFT_BLACK);

	// Attach the rotary encode interrupt.
	pinMode(PIN_ENCODER_A, INPUT_PULLUP);
	int pinIntrEncoderA = digitalPinToInterrupt(PIN_ENCODER_A);
	attachInterrupt(pinIntrEncoderA, EncoderChangeEvent, CHANGE);
	pinMode(PIN_ENCODER_B, INPUT_PULLUP);
	int pinIntrEncoderB = digitalPinToInterrupt(PIN_ENCODER_B);
	attachInterrupt(pinIntrEncoderB, EncoderChangeEvent, CHANGE);

	// Launch the initial page.  This will not exit.
	_navigator.StartWith(PageName::Main);
}

void loop() 
{}

void manageTemp()
{
	_tempSvc.ManageIron();
}

void EncoderChangeEvent()
{ 
	_mainPage.HandleEncoderChange();

	// Get the current page and, if there is one, ask it to handle the encoder change event.
	PageBase* currentPage = _navigator.GetCurrentPage();
	if(currentPage!=NULL)
	{
		currentPage->HandleEncoderChange();
	}
}
