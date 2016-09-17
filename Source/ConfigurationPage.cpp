#include "ConfigurationPage.h"

/*
	Initialise the page.
*/
void ConfigurationPage::Setup()
{
	Serial.println("> ConfigurationPage::Prepare()");

	LCD->fillScreen(TFT_BLUE);

	Serial.println("< ConfigurationPage::Prepare()");
}

/*
	Loop execution of the page.  The page code can exit the loop and specify the next page who should be displayed and executed.
*/
PageName ConfigurationPage::Loop()
{
	Serial.println("> ConfigurationPage::Execute()");

	delay(5000);

	Serial.println("< ConfigurationPage::Execute()");

	return PageName::Main;
}

