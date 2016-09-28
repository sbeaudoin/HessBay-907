#pragma once

#include "PageBase.h"
#include "Global.h"
#include "SmallFont.h"
#include "NormalFont.h"
#include "NormalFontBold.h"
#include "NormalNumbersBols.h"
#include "Rotate.h"
#include "RotateSelect.h"
#include "BigNumbersBold.h"
#include <TFT_HX8357.h>
#include <Arduino.h>
#include "EncoderDriver.h"
#include "TempControlService.h"

/*
	Main page of the unit.  Display the available temperature profiles and the current solder iron temperature.
*/
class MainPage : public PageBase
{
	public :

		/*
			Initialize the instance.

			IN
			--
			*lcdDriver : Instance of the LCD driver.
		*/
		MainPage(TFT_HX8357 *lcdDriver, EncoderDriver *encoderDriver, TempControlService *tempSvc) 
			: PageBase(lcdDriver, encoderDriver, tempSvc) 
		{};

		/*
			Initialise the page.
		*/
		void Setup();

		/*
			Loop execution of the page.  The page code can exit the loop and specify the next page who should be displayed and 
			executed.

			OUT
			---
			The name of the page who should be displayed and executed once the page code exit the loop.
		*/
		PageName Loop();

		void HandleEncoderChange();

	private :

		/*
			The currently selected profile.
		*/
		ProfileName SelectedProfile;

		/*
			The selected temperatures for each profiles or 0 if not set.
		*/
		int ProfileTemp[2];

		/*
			Display the header of the page.
		*/
		void PrepareHeader();

		/*
			Display the default load level.
		*/
		void PrepareLoadLevel();

		/*
			Display the profile box for the specified profile.

			IN
			--
			profile : The profile name for which the profile box should be displayed.
		*/
		void PrepareProfile(ProfileName profile);

		/*
			Display the footer of the page.  
		*/
		void PrepareFooter();

		/*
			Change the temperature for the specified profile.

			IN
			--
			profile : The profile for which the temperature changed.
			temp    : The selected temperature for the profile.  It is 0 if it is not set.
		*/
		void UpdateProfileTemperature(ProfileName profile, int temp);

		/*
			Change the selected profile.

			IN
			--
			profile : The profile who should be selected or 'None' if no profile should be selected.
		*/
		void SelectProfile(ProfileName profile);

		/*
			Change the load level value.

			IN
			--
			load : The current load in %.
		*/
		void UpdateLoadLevelValue(int load);

		/*
			Change the displayed iron temperature.

			IN
			--
			temp : The current iron temperature.
		*/
		void UpdateCurrentTemp(int temp);

		/*
			Show the target temperature for the soldering iron.

			IN
			--
			temp : The target temperature for the soldering iron.
		*/
		void UpdateTargetTemp(int temp);

		//int GetCurrentIronTemp();

		//void SetcurrentIronLoad(int loadPercent);

		//void ManageLoadChange();

		int _currentTargetTemp;

		int _currentLoad;

		int _currentTemp;
};
