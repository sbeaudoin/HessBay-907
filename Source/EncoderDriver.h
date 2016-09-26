#pragma once

#include <Arduino.h>

/*
	This class drive a rotary encoder.  It uses the defined pins for the A and B channel of the encoder.  As the pins can be
	configured to use the internal pull-up resistors, they are optional.

	The consumer of this class must declare and interrupt on pin change of the A and B channels.  In the interrupt method, the
	'ReadDelta' method of this class should be called to get the new value.

	Technical notes
	===============

	Encoder pins signal
	-------------------

	<--Negative--Positive-->
		   ___
	A ____|   |_

	     ___
	B __|   |___

	   ^ ^ ^ ^
	   | | | |
	   | | | +-[H/L]
	   | | +-[H/H]
	   | +-[L/H]
	   +-[L/L]

	Full resolution transitions
	+--------------+---------+-------------------------+-------------+
	| Previous A/B | New A/B | Result                  | State value |
	+--------------+---------+-------------------------+-------------+
	| L/L          | L/L     | --                      | 0000 = 0    |
	| L/L          | L/H     | +1                      | 0001 = 1    |
	| L/L          | H/L     | -1                      | 0010 = 2    |
	| L/L          | H/H     | +2 (missed one +1 step) | 0011 = 3    |
	+--------------+---------+-------------------------+-------------+
	| L/H          | L/L     | -1                      | 0100 = 4    |
	| L/H          | L/H     | --                      | 0101 = 5    |
	| L/H          | H/L     | -2 (missed one -1 step) | 0110 = 6    |
	| L/H          | H/H     | +1                      | 0111 = 7    |
	+--------------+---------+-------------------------+-------------+
	| H/L          | L/L     | +1                      | 1000 = 8    |
	| H/L          | L/H     | -2 (missed one -1 step) | 1001 = 9    |
	| H/L          | H/L     | --                      | 1010 = 10   |
	| H/L          | H/H     | -1                      | 1011 = 11   |
	+--------------+---------+-------------------------+-------------+
	| H/H          | L/L     | +2 (missed one +1 step) | 1100 = 12   |
	| H/H          | L/H     | -1                      | 1101 = 13   |
	| H/H          | H/L     | +1                      | 1110 = 14   |
	| H/H          | H/H     | --                      | 1111 = 15   |
	+--------------+---------+-------------------------+-------------+

	Full resolution clockwise transitions (4 transitions per click)
	+--------------+---------+--------+
	| Previous A/B | New A/B | Change |
	+--------------+---------+--------+
	| H/H          | H/L     | -/D    |
	| H/L          | L/L     | D/-    |
	| L/L          | L/H     | -/U    |
	| L/H          | H/H     | U/-    |
	+--------------+---------+--------+

	Full resolution counter-clockwise transitions (4 transitions per click)
	+--------------+---------+--------+
	| Previous A/B | New A/B | Change |
	+--------------+---------+--------+
	| H/H          | L/H     | D/-    |
	| L/H          | L/L     | -/D    |
	| L/L          | H/L     | U/-    |
	| H/L          | H/H     | -/U    |
	+--------------+---------+--------+

	Normal resolution transitions (1 transition per click)
	- If A goes from H to L and B is L : Clockwise
	- If A goes from H to L and B is H : Counter-clockwise
*/

class EncoderDriver
{
	public :

	EncoderDriver()
	{ }

	/*
		Initialize a new instance.

		INPUT
		-----
		channelAPin    : Pin used for the channel A pin of the encoder.  Must be an interrupt pin.
		channelBpin    : Pin used for the channel B pin of the encoder.  Must be an interrupt pin.
		pullUpInternal : If true, the internal pull up resistor of the controller will be used.  If false, you must put a pull
						 up resistor yourself.
	*/
	EncoderDriver(byte channelAPin, byte channelBPin, bool pullUpInternal)
	{
		_pinA = channelAPin;
		_pinB = channelBPin;

		// Find the input type who must be used and initialize the input pins.
		byte inputType = (pullUpInternal) ? INPUT_PULLUP : INPUT;
		pinMode(channelAPin, inputType);
		pinMode(channelBPin, inputType);

		// Check the initial state.
		_prevA = digitalRead(channelAPin);
		_prevB = digitalRead(channelBPin);
	}

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
	int ReadDelta(bool fullResolution);

	private :

	/*
		Pin used for the channel A of the encoder.
	*/
	byte _pinA;

	/*
		Pin used for the channel B of the encoder.
	*/
	byte _pinB;

	/*
		Previous state of the channel A pin.
	*/
	byte _prevA;

	/*
		Previous state of the channel B pin.
	*/
	byte _prevB;

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
	int ReadDeltaFullRes(byte newA, byte newB);

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
	int ReadDeltaNormalRes(byte newA, byte newB);
};
