#pragma once

#include "Global.h"

class TempControlService
{
	public:

		enum States { Off, Sleeping, On };

		TempControlService()
		{ 
			_targetTemp = LAST_TARGET_TEMP;
			_currentTemp = GetIronTemp();
			_sleepTemp = SLEEP_TEMP;
			_sleepDelaySeconds = SLEEP_DELAY_SECONDS;
			_autoOffDelaySeconds = AUTO_OFF_DELAY_SECONDS;
			Wake();
		};

		void Sleep();
		void Wake();
		States GetCurrentState();
		void SetTargetTemp(int temp);
		int GetTargetTemp();
		int GetCurrentTemp();
		int GetCurrentLoad();
		int GetEffectiveTargetTemp();
		void ManageIron();

	private :

		int GetIronTemp();
		int _targetTemp;
		int _currentTemp;
		int _sleepTemp;
		int _sleepDelaySeconds;
		int _autoOffDelaySeconds;
		States _currentState;
		int _currentLoad;
		int _effectiveTargetTemp;
};
