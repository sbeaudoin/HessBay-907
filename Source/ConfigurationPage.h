#pragma once

#include "PageBase.h"
#include "Global.h"
#include <TFT_HX8357.h>

class ConfigurationPage : public PageBase
{

public:

	ConfigurationPage(TFT_HX8357* lcdDriver) : PageBase(lcdDriver)
	{};

	void Setup();
	PageName Loop();

private:

};
