#include "EncoderDriver.h"

/*
	Read the encoder position and return the delta relative to the initial state if it is the first read or the previous read
	if it is a subsequent read.

	INPUT
	-----
	fullResolution  : If true, each click of the encoder produce 4 value changes.  If false, each click product one value
	change.

	OUTPUT
	------
	A negative number if a counter-clockwise change as been produced or a positive number if a clockwise change as been
	produced.  The value correspond to the number of value changes produced.  A return value of 0 indicate no changes.
*/
int EncoderDriver::ReadDelta(bool fullResolution)
{
	// Read the new pin states.
	int newA = digitalRead(_pinA);
	int newB = digitalRead(_pinB);

	int delta = 0;

	if(fullResolution)
	{
		delta = ReadDeltaFullRes(newA, newB);
	}
	else // Normal resolution.  One value change per click.
	{
		delta = ReadDeltaNormalRes(newA, newB);
	}

	_prevA = newA;
	_prevB = newB;

	return delta;
}

/*
	Read the encoder and produce a full resolution delta.

	INPUT
	-----
	newA : New state of the channel A of the encoder.
	newB : New state of the channel B of the encoder.

	OUTPUT
	------
	A negative number if a counter-clockwise change as been produced or a positive number if a clockwise change as been
	produced.  The value correspond to the number of value changes produced.  A return value of 0 indicate no changes.
*/
int EncoderDriver::ReadDeltaFullRes(byte newA, byte newB)
{
	int delta = 0;

	// Product a state byte with the following binary format.
	//
	//		ABCD
	//		^^^^
	//      |||+-- New channel B state.
	//      ||+--- New channel A state.
	//      |+---- Previous channel B state.
	//      +----- Previous channel A state.
	byte state = 0;
	state = _prevA<<3 | _prevB<<2 | newA<<1 | newB;

	// Find the delta depending of the state change.
	switch(state)
	{
		case 1:  // 00->01 : A is low and unchanged, B changed from low to high.
		case 7:  // 01->11 : A changed from low to high, B is high and unchanged.
		case 8:  // 10->00 : A changed from high to low, B is low and unchanged.
		case 14: // 11->10 : A is high and unchanged, B changed from high to low.
			delta = 1;
			break;

		case 2:  // 00->10 : A changed from low to high, B is low and unchanged.
		case 4:  // 01->00 : A is unchanged and low, B changed from high to low.
		case 11: // 10->11 : A is unchanged and high, B changed from low to high.
		case 13: // 11->01 : A changed from high to low, B is unchanged and high.
			delta = -1;
			break;

		case 3:  // 00->11 : A and B changed from low to high.
		case 12: // 11->00 : A and B changed from high to low.

			// We missed a clockwise step and received a clockwise step.
			delta = 2;
			break;

		case 6: // 01->10 : A changed from low to high, B changed from high to low.
		case 9: // 10->01 : A changed from high to low, B changed from low to high.

			// We missed a counter-clockwise step and received a counter-clockwise step.
			delta = -2;
			break;

	}

	return delta;
}

/*
	Read the encoder and produce a normal resolution delta.

	INPUT
	-----
	newA : New state of the channel A of the encoder.
	newB : New state of the channel B of the encoder.

	OUTPUT
	------
	A negative number if a counter-clockwise change as been produced or a positive number if a clockwise change as been
	produced.  The value correspond to the number of value changes produced.  A return value of 0 indicate no changes.
*/
int EncoderDriver::ReadDeltaNormalRes(byte newA, byte newB)
{ 
	int delta = 0;
	if(_prevA==HIGH && newA==LOW)
	{
		if(newB==LOW)
		{
			delta = 1;
		}
		else // B is HIGH
		{
			delta = -1;
		}
	}

	return delta;
}
