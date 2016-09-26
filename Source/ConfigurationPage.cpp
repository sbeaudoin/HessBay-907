#include "ConfigurationPage.h"

/*
	Initialise the page.
*/
void ConfigurationPage::Setup()
{
	LCD->fillScreen(TFT_BLUE);
}

/*
	Loop execution of the page.  The page code can exit the loop and specify the next page who should be displayed and executed.
*/
PageName ConfigurationPage::Loop()
{
	delay(5000);

	return PageName::Main;
}

void ConfigurationPage::HandleEncoderChange()
{

}

