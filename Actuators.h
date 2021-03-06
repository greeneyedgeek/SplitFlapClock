/*

	Project:	SplitFlapClock
	File:		Actuators.h
	Created:	2019-04-10
	Modified:	2019-04-10
	Author:		Gabriel Fontaine-Escobar
	Version:	0.1

	Description:


 	This code is in the public domain.
	https://github.com/greeneyedgeek/SplitFlapClock

 	MIT License

	Copyright (c) 2019 Gabriel Fontaine-Escobar

	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
	documentation files (the "Software"), to deal in the Software without restriction, including without limitation
	the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
	and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
	LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
	IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef ACTUATORS_H
#define ACTUATORS_H

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

typedef uint8_t Direction;
typedef uint16_t Steps;
typedef uint8_t Delay;
typedef volatile uint8_t Port;
typedef uint8_t Mask;

enum{clockwise, counterclockwise};

namespace Actuators
{
	class Steppers
	{
	public:
		Steppers(Port* port, Mask mask);
		void rotate(Direction direction, Steps steps, Delay ms);
	private:
		Port* port;
		Mask mask;
		static uint8_t port_values[8];
	};
}

#endif // ACTUATORS_H
