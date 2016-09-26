#pragma once

#include "PageBase.h"
#include "Global.h"
#include <TFT_HX8357.h>

class ConfigurationPage : public PageBase
{

public:

	ConfigurationPage(TFT_HX8357* lcdDriver, EncoderDriver* encoderDriver) : PageBase(lcdDriver, encoderDriver)
	{};

	void Setup();
	PageName Loop();
	void HandleEncoderChange();

private:

};
