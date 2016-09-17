#include "TFT_HX8357.h"
#include "PageBase.h"
#include "MainPage.h"
#include "ConfigurationPage.h"
#include "PageEntry.h"
#include "Navigator.h"

TFT_HX8357 _lcdDriver = TFT_HX8357(480, 320);

/*
	Initialize the pages used in the sketch.
*/
MainPage _mainPage = MainPage(&_lcdDriver);
ConfigurationPage _configPage = ConfigurationPage(&_lcdDriver);

/*
	Associate the page with a static name and put this in a PageEntry.
*/
PageEntry _mainPageEntry = PageEntry(PageName::Main, &_mainPage);
PageEntry _configPageEntry = PageEntry(PageName::Configuration, &_configPage);

/*
	Initialize the navigator.
*/
PageEntry _entries [] = { _mainPageEntry, _configPageEntry };
Navigator<2> _navigator = Navigator<2>(_entries);

void setup() 
{
	// Initialize the LCD driver.
	_lcdDriver.begin();
	_lcdDriver.setRotation(3); // As I use a ILI9481, I must set my screen upside/down.
	_lcdDriver.fillScreen(TFT_BLACK);

	// Launch the initial page.  This will not exit.
	_navigator.StartWith(PageName::Main);
}

void loop() 
{
	// Nothing will be executed here.
}
