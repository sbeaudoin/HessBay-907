#include "TempControlService.h"

TempControlService::States TempControlService::GetCurrentState()
{
	return _currentState;
}

int TempControlService::GetCurrentTemp()
{
	return _currentTemp;
}

int TempControlService::GetTargetTemp()
{
	return _targetTemp;
}

void TempControlService::SetTargetTemp(int temp)
{
	_targetTemp = temp;
	_effectiveTargetTemp = temp;
	ManageIron();
}

void TempControlService::Sleep()
{
	_effectiveTargetTemp = SLEEP_TEMP;
	_currentState = States::Sleeping;
	ManageIron();
}

void TempControlService::Wake()
{
	_effectiveTargetTemp = _targetTemp;
	_currentState = States::On;
	ManageIron();
}

int TempControlService::GetCurrentLoad()
{
	return _currentLoad;
}

int TempControlService::GetEffectiveTargetTemp()
{
	return _effectiveTargetTemp;
}

void TempControlService::ManageIron()
{
	// Read current temp from iron.
	// _currentTemp = Iron;

	if(_effectiveTargetTemp>_currentTemp)
	{
		// Calculate load from target temp.
		// Set load.
	}
	else
	{ 
		_currentLoad = 0;
	}
}

int TempControlService::GetIronTemp()
{
	return 0;
}

