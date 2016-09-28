#pragma once

#include "PageBase.h"
#include "Global.h"
#include <TFT_HX8357.h>
#include "TempControlService.h"

class ConfigurationPage : public PageBase
{

public:

	ConfigurationPage(TFT_HX8357* lcdDriver, EncoderDriver* encoderDriver, TempControlService* tempSvc) 
		: PageBase(lcdDriver, encoderDriver, tempSvc)
	{};

	void Setup();
	PageName Loop();
	void HandleEncoderChange();

private:

};
