/*
	TODO
	----
	- If the profile temperature is 0, show nothing.
	- In UpdateProfileTemp, consider the case where the selected profile is None.
*/

#include "MainPage.h"

/*
	Display the header of the page.
*/
void MainPage::PrepareHeader()
{
	// Show the product name.
	LCD->setFreeFont(&NormalFontBold);
	LCD->fillRect(0, 0, 479, 26, TFT_DARKGREEN);
	LCD->setTextColor(TFT_WHITE, TFT_DARKGREEN);
	LCD->drawCentreString("HessBay 907 Intelligent Station", 240, 4, 1);

	// Show the firmware version.
	char versionArray[12];
	VERSION.toCharArray(versionArray, 12, 0);
	LCD->setFreeFont(&SmallFont);
	LCD->setTextColor(TFT_LIGHTGREY, TFT_DARKGREEN);
	LCD->drawRightString(versionArray, 476, 7, 1);
}

/*
	Display the default load level.
*/
void MainPage::PrepareLoadLevel()
{
	LCD->setFreeFont(&SmallFont);
	LCD->setTextColor(TFT_DARKGREY, TFT_BLACK);
	LCD->drawString("Load", 446, 55, 1);
	LCD->drawRect(446, 69, 33, 102, TFT_DARKGREEN);
}

/*
	Display the profile box for the specified profile.

	IN
	--
	profile : The profile name for which the profile box should be displayed.
*/
void MainPage::PrepareProfile(ProfileName profile)
{
	// Only if a valid profile is specified.
	if (profile!=ProfileName::None)
	{
		// Display the profile section header.
		LCD->setTextColor(TFT_DARKGREY, TFT_BLACK);
		LCD->setFreeFont(&NormalFont);
		LCD->drawString("Temperature Profiles", 0, 178, 1);

		// Calculate the origin of the upper left corner.
		int originX = ((int)profile - 1) * 165;

		// If the specified profile is the one who is selected.
		if(SelectedProfile==profile)
		{
			LCD->fillRoundRect(originX, 203, 150, 75, 5, TFT_DARKGREEN);
			LCD->fillRect(originX+3, 207, 142, 19, TFT_DARKGREEN);
		}
		else // The profile is not selected.
		{
			LCD->fillRoundRect(originX, 203, 150, 75, 5, TFT_WHITE);
			LCD->fillRect(originX+3, 207, 142, 19, TFT_DARKGREEN);
		}

		// Get the profile name to be displayed.
		String profileName;
		switch (profile)
		{
			case ProfileName::ProfileA:
				profileName = "Profile A";
				break;

			case ProfileName::ProfileB:
				profileName = "Profile B";
				break;

			case ProfileName::ProfileC:
				profileName = "Profile C";
				break;
		}

		// Display the profile name.
		char profileNameArray[12];
		profileName.toCharArray(profileNameArray, 12, 0);
		LCD->setTextColor(TFT_WHITE, TFT_DARKGREEN);
		LCD->setFreeFont(&SmallFont);
		LCD->drawCentreString(profileNameArray, originX + (150 / 2), 212, 1);
	}
}

/*
	Display the footer of the page.
*/
void MainPage::PrepareFooter()
{
	// Set the font and its colour.
	LCD->setFreeFont(&NormalFont);
	LCD->setTextColor(TFT_WHITE, TFT_DARKGREEN);

	// Draw the left side.
	LCD->fillRect(0, 293, 200, 26, TFT_DARKGREEN);
	LCD->drawString("Manual Temp.", 30, 297, 1);
	LCD->drawBitmap(4, 298, Rotate, 16, 16, TFT_BLACK);

	// Draw the right side.
	LCD->fillRect(279, 293, 200, 26, TFT_DARKGREEN);
	LCD->drawString("Configuration", 309, 297, 1);
	LCD->drawBitmap(283, 298, RotateSelect, 16, 16, TFT_BLACK);
}

/*
	Initialize the page.
*/
void MainPage::Setup()
{
	LCD->fillScreen(TFT_BLACK);

#ifdef TEST_MODE

	// Show default profile values.
	SelectedProfile = ProfileName::None;
	ProfileTemp[0] = 100;
	ProfileTemp[1] = 200;
	ProfileTemp[2] = 300;
#endif

	// Display the initial presentation of the page without values.
	PrepareHeader();
	PrepareLoadLevel();
	PrepareFooter();
	PrepareProfile(ProfileName::ProfileA);
	PrepareProfile(ProfileName::ProfileB);
	PrepareProfile(ProfileName::ProfileC);
}

/*
	Loop execution of the page.  The page code can exit the loop and specify the next page who should be displayed and executed.
*/
PageName MainPage::Loop()
{
	// Display the current profiles temp.
	UpdateProfileTemperature(ProfileName::ProfileA, ProfileTemp[0]);
	UpdateProfileTemperature(ProfileName::ProfileB, ProfileTemp[1]);
	UpdateProfileTemperature(ProfileName::ProfileC, ProfileTemp[2]);

#ifdef TEST_MODE

	// Make sure the profiles are drawn correctly when the selected profile go to None.
	SelectProfile(ProfileName::None);
	delay(1000);
	SelectProfile(ProfileName::ProfileA);
	delay(1000);
	SelectProfile(ProfileName::None);
	delay(1000);
	SelectProfile(ProfileName::ProfileB);
	delay(1000);
	SelectProfile(ProfileName::None);
	delay(1000);
	SelectProfile(ProfileName::ProfileC);
	delay(1000);
	SelectProfile(ProfileName::None);

	// Make sure the profiles are drawn correctly when the selected profile goes from one value to the other.
	delay(1000);
	SelectProfile(ProfileName::ProfileA);
	delay(1000);
	SelectProfile(ProfileName::ProfileB);
	delay(1000);
	SelectProfile(ProfileName::ProfileC);

	// Test the value update of the different parts of the page.
	int load = 0;
	for (int i = 0; i < 100; i += 10)
	{
		// The load go up one block at each iteration and is reset when at 10/10.
		UpdateLoadLevelValue(load++);
		if (load > 10)
		{
			load = 0;
		}

		// Update the main temperature ten degrees at each iteration.
		UpdateMainTemperature(i);

		// Update the profile values at each iteration.
		UpdateProfileTemperature(ProfileName::ProfileA, i + 10);
		UpdateProfileTemperature(ProfileName::ProfileB, i + 15);
		UpdateProfileTemperature(ProfileName::ProfileC, i + 20);

		delay(500);
	}

#endif

	// When the rotary encoder is pressed, we go to the configuration page.
	return PageName::Configuration;
}

/*
	Change the temperature for the specified profile.

	IN
	--
	profile : The profile for which the temperature changed.
	temp    : The selected temperature for the profile.  It is 0 if it is not set.
*/
void MainPage::UpdateProfileTemperature(ProfileName profile, int temp)
{
	// Calculate the origin of the upper left corner of the profile.
	int originX = ((int)profile - 1) * 165;

	// Generate the string temperature with the degree symbol and unit.
	String tempString = String(temp) + ""; // For degree symbol and "C"
	char tempArray[6];
	tempString.toCharArray(tempArray, 6, 0);

	// Clear the section used by the temperature.  The color used depend on the selection state.
	if (profile == SelectedProfile)
	{
		LCD->fillRect(originX + 4, 237, 141, 32, TFT_DARKGREEN);
		LCD->setTextColor(TFT_BLACK, TFT_DARKGREEN);
	}
	else // Profile is not selected
	{
		LCD->fillRect(originX + 4, 237, 141, 32, TFT_WHITE);
		LCD->setTextColor(TFT_BLACK, TFT_WHITE);
	}

	// display the temperature for this profile.
	LCD->setFreeFont(&NormalNumbersBold);
	if (ProfileTemp[(int)profile - 1]>0)
	{
		LCD->drawCentreString(tempArray, originX + (150 / 2), 237, 1);
	}
	else // No temperature set for this profile.
	{
		LCD->drawCentreString("0", originX + (150 / 2), 237, 1);
	}

	// Keep the temperature for the profile.
	ProfileTemp[(int)profile - 1] = temp;
}

/*
	Change the selected profile.

	IN
	--
	profile : The profile who should be selected or 'None' if no profile should be selected.
*/
void MainPage::SelectProfile(ProfileName profile)
{
	int originX;

	// If a profile is already selected, and it is not the one received in parameter, clear it.
	if (SelectedProfile != ProfileName::None && SelectedProfile!=profile)
	{
		// Keep the old selected profile and reset the new one.
		ProfileName clearedProfile = SelectedProfile;
		SelectedProfile = ProfileName::None;

		// Clear the selection for the old selected profile.
		originX = (clearedProfile - 1) * 165;
		PrepareProfile(clearedProfile);
		UpdateProfileTemperature(clearedProfile, ProfileTemp[clearedProfile - 1]);
	}

	// There is a newly selected profile.
	if (profile != ProfileName::None)
	{
		// Select this profile.
		SelectedProfile = profile;
		PrepareProfile(SelectedProfile);
		UpdateProfileTemperature(SelectedProfile, ProfileTemp[SelectedProfile - 1]);
	}
}

/*
	Change the load level value.

	IN
	--
	load : The current load in block of 10%.
*/
void MainPage::UpdateLoadLevelValue(int load)
{
	// Protect ourselves from overflow.
	if (load > 10)
	{
		load = 10;
	}

	// The color is green by default.
	uint16_t couleur = TFT_GREEN;
	if (load > 7)
	{
		// The color is red for ]7..10].
		couleur = TFT_RED;
	}
	else if (load>3)
	{
		// The color is orange for ]3..7].
		couleur = TFT_ORANGE;
	}

	// Draw the load level.
	int pixelCount = load * 10;
	LCD->fillRect(447, 70, 31, 100 - pixelCount, TFT_BLACK);
	LCD->fillRect(447, 70 + (100 - pixelCount), 31, pixelCount, couleur);
}

/*
	Change the displayed iron temperature.

	IN
	--
	The current iron temperature.
*/
void MainPage::UpdateMainTemperature(int temp)
{
	// Draw the label.
	LCD->setFreeFont(&NormalFont);
	LCD->setTextColor(TFT_DARKGREY, TFT_BLACK);
	LCD->drawString("Current Temperature", 0, 37, 1);

	// Generate the temperature string with the degree symbol and unit.
	String tempString = String(temp) + "-."; // For the degree symbol and "C".
	char tempArray[6];
	tempString.toCharArray(tempArray, 6, 0);

	// Clear the old value and display the new one.
	LCD->setFreeFont(&BigNumbersBold);
	LCD->fillRect(0, 59, 350, 102, TFT_BLACK);
	LCD->setTextColor(TFT_RED, TFT_BLACK);
	LCD->drawString(tempArray, 0, 66, 1);
}