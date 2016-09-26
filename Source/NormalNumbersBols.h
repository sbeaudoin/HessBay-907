#pragma once

/*
	Thanks for Robert Jablonski for the Falling Sky font (http://www.fontspace.com/cannot-into-space-fonts/falling-sky).
*/

/*
	Falling Sky font bold 24pt, numbers and some other chars.

	The following chars as been modified.

	- 0x2C : Supposed to be ',', but will display the degree symbol.
	- 0x2D : Supposed to be '-', but will display "C".
	- 0x2E : Supposed to be '.', but will display "F".

	The character '/' (0x2F) as been added.
*/
const uint8_t NormalNumbersBoldBitmaps [] PROGMEM = {
	0x00, 0xFC, 0x00, 0x0F, 0xFC, 0x00, 0x7F, 0xFC, 0x03, 0xFF, 0xF0, 0x1F,
	0xFF, 0xE0, 0xFF, 0xFF, 0xC3, 0xF8, 0x7F, 0x0F, 0xC0, 0xFE, 0x7F, 0x01,
	0xF9, 0xF8, 0x07, 0xE7, 0xE0, 0x1F, 0x9F, 0x80, 0x7F, 0x7E, 0x01, 0xFF,
	0xF8, 0x07, 0xFF, 0xE0, 0x1F, 0xFF, 0x80, 0x7F, 0xFE, 0x01, 0xFF, 0xF8,
	0x07, 0xFF, 0xE0, 0x1F, 0xDF, 0x80, 0x7F, 0x7E, 0x01, 0xF9, 0xF8, 0x07,
	0xE7, 0xE0, 0x1F, 0x9F, 0xC0, 0x7E, 0x3F, 0x03, 0xF8, 0xFE, 0x1F, 0xC3,
	0xFD, 0xFF, 0x07, 0xFF, 0xF8, 0x0F, 0xFF, 0xC0, 0x1F, 0xFE, 0x00, 0x3F,
	0xF0, 0x00, 0x3F, 0x00, 0x03, 0xF0, 0xFF, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xF0, 0x7F, 0x07, 0xF0, 0x7F, 0x07, 0xF0, 0x7F, 0x07, 0xF0,
	0x7F, 0x07, 0xF0, 0x7F, 0x07, 0xF0, 0x7F, 0x07, 0xF0, 0x7F, 0x07, 0xF0,
	0x7F, 0x07, 0xF0, 0x7F, 0x07, 0xF0, 0x7F, 0x07, 0xF0, 0x7F, 0x07, 0xF0,
	0x7F, 0x01, 0xFC, 0x00, 0x3F, 0xFC, 0x01, 0xFF, 0xF8, 0x1F, 0xFF, 0xF0,
	0xFF, 0xFF, 0xE3, 0xFE, 0xFF, 0x87, 0xC0, 0xFF, 0x0E, 0x01, 0xFC, 0x10,
	0x03, 0xF0, 0x00, 0x0F, 0xC0, 0x00, 0x3F, 0x00, 0x00, 0xFC, 0x00, 0x07,
	0xF0, 0x00, 0x1F, 0x80, 0x00, 0xFE, 0x00, 0x07, 0xF0, 0x00, 0x1F, 0xC0,
	0x00, 0xFE, 0x00, 0x07, 0xF0, 0x00, 0x3F, 0xC0, 0x01, 0xFE, 0x00, 0x0F,
	0xF0, 0x00, 0x7F, 0x80, 0x03, 0xFC, 0x00, 0x1F, 0xE0, 0x00, 0xFF, 0xFF,
	0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xC0, 0x01, 0xFC, 0x00, 0x7F, 0xFC, 0x07, 0xFF, 0xF0, 0xFF,
	0xFF, 0xC7, 0xFF, 0xFE, 0x3F, 0xDF, 0xF8, 0xF0, 0x1F, 0xC3, 0x00, 0x7E,
	0x00, 0x03, 0xF0, 0x00, 0x1F, 0x80, 0x01, 0xFC, 0x00, 0x0F, 0xE0, 0x01,
	0xFE, 0x01, 0xFF, 0xE0, 0x0F, 0xFE, 0x00, 0x7F, 0xE0, 0x03, 0xFF, 0xC0,
	0x1F, 0xFF, 0x00, 0x07, 0xFC, 0x00, 0x0F, 0xF0, 0x00, 0x3F, 0x80, 0x00,
	0xFC, 0x00, 0x07, 0xE4, 0x00, 0x3F, 0x70, 0x03, 0xFB, 0xE0, 0x3F, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xFF, 0xFE, 0x1F, 0xFF, 0xE0, 0x7F, 0xFE,
	0x00, 0x7F, 0x80, 0x00, 0x0F, 0xF0, 0x00, 0x3F, 0xE0, 0x00, 0x7F, 0xC0,
	0x01, 0xFF, 0x80, 0x07, 0xFF, 0x00, 0x0F, 0xFE, 0x00, 0x3F, 0xFC, 0x00,
	0xFF, 0xF8, 0x01, 0xFB, 0xF0, 0x07, 0xEF, 0xE0, 0x1F, 0xDF, 0xC0, 0x3F,
	0x3F, 0x80, 0xFC, 0x7F, 0x03, 0xF8, 0xFE, 0x07, 0xE1, 0xFC, 0x1F, 0x83,
	0xF8, 0x7F, 0x07, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x01, 0xFC, 0x00, 0x03, 0xF8,
	0x00, 0x07, 0xF0, 0x00, 0x0F, 0xE0, 0x00, 0x1F, 0xC0, 0x00, 0x3F, 0x80,
	0x00, 0x7F, 0x00, 0x00, 0xFE, 0x00, 0x1F, 0xFF, 0xF0, 0xFF, 0xFF, 0x87,
	0xFF, 0xFC, 0x3F, 0xFF, 0xE1, 0xFF, 0xFE, 0x0F, 0xFF, 0xF0, 0xFE, 0x00,
	0x07, 0xF0, 0x00, 0x3F, 0x00, 0x01, 0xF8, 0x00, 0x0F, 0xC0, 0x00, 0x7E,
	0xFC, 0x03, 0xFF, 0xF8, 0x1F, 0xFF, 0xF0, 0xFF, 0xFF, 0x87, 0xFF, 0xFE,
	0x1F, 0x0F, 0xF8, 0x60, 0x1F, 0xC0, 0x00, 0xFE, 0x00, 0x03, 0xF0, 0x00,
	0x1F, 0x80, 0x00, 0xFC, 0x00, 0x07, 0xE4, 0x00, 0x7F, 0x70, 0x03, 0xFB,
	0xE0, 0x3F, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xC7, 0xFF, 0xFE, 0x1F, 0xFF,
	0xE0, 0x7F, 0xFC, 0x00, 0x7F, 0x80, 0x00, 0x7E, 0x00, 0x1F, 0xFE, 0x01,
	0xFF, 0xF8, 0x1F, 0xFF, 0xE1, 0xFF, 0xFF, 0x1F, 0xFF, 0xF0, 0xFE, 0x07,
	0x0F, 0xE0, 0x10, 0x7E, 0x00, 0x07, 0xF0, 0x00, 0x3F, 0x00, 0x01, 0xF8,
	0x00, 0x0F, 0xC7, 0xE0, 0x7E, 0xFF, 0xC3, 0xFF, 0xFF, 0x1F, 0xFF, 0xFC,
	0xFF, 0xFF, 0xF7, 0xFC, 0x3F, 0xBF, 0x80, 0xFF, 0xF8, 0x07, 0xFF, 0xC0,
	0x1F, 0xFE, 0x00, 0xFF, 0xF0, 0x07, 0xFF, 0xC0, 0x3F, 0x7E, 0x03, 0xFB,
	0xF8, 0x1F, 0x8F, 0xF3, 0xFC, 0x7F, 0xFF, 0xC1, 0xFF, 0xFE, 0x07, 0xFF,
	0xE0, 0x1F, 0xFC, 0x00, 0x1F, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xFF, 0xFF, 0xE0, 0x00,
	0x3F, 0x00, 0x01, 0xF8, 0x00, 0x0F, 0xC0, 0x00, 0x3F, 0x00, 0x01, 0xF8,
	0x00, 0x07, 0xE0, 0x00, 0x3F, 0x00, 0x00, 0xFC, 0x00, 0x07, 0xE0, 0x00,
	0x1F, 0x80, 0x00, 0xFE, 0x00, 0x03, 0xF0, 0x00, 0x0F, 0xC0, 0x00, 0x3F,
	0x00, 0x01, 0xFC, 0x00, 0x07, 0xF0, 0x00, 0x1F, 0xC0, 0x00, 0x7E, 0x00,
	0x01, 0xF8, 0x00, 0x07, 0xE0, 0x00, 0x1F, 0x80, 0x00, 0xFE, 0x00, 0x03,
	0xF8, 0x00, 0x0F, 0xE0, 0x00, 0x00, 0xFE, 0x00, 0x0F, 0xFE, 0x00, 0xFF,
	0xFC, 0x07, 0xFF, 0xF8, 0x1F, 0xFF, 0xF0, 0xFE, 0x1F, 0xC3, 0xF0, 0x3F,
	0x0F, 0xC0, 0x7E, 0x3F, 0x01, 0xF8, 0xFC, 0x07, 0xE3, 0xF0, 0x1F, 0x0F,
	0xE0, 0xFC, 0x1F, 0xE3, 0xF0, 0x7F, 0xFF, 0x80, 0xFF, 0xFC, 0x01, 0xFF,
	0xE0, 0x0F, 0xFF, 0xC0, 0x7F, 0xFF, 0x83, 0xF1, 0xFF, 0x1F, 0x81, 0xFE,
	0x7E, 0x03, 0xF9, 0xF0, 0x07, 0xFF, 0xC0, 0x1F, 0xFF, 0x00, 0x3F, 0xFE,
	0x01, 0xFD, 0xF8, 0x07, 0xF7, 0xF8, 0x3F, 0x8F, 0xFF, 0xFE, 0x3F, 0xFF,
	0xF0, 0x7F, 0xFF, 0x80, 0x7F, 0xF8, 0x00, 0x7F, 0x80, 0x01, 0xFC, 0x00,
	0x1F, 0xFC, 0x00, 0xFF, 0xF8, 0x07, 0xFF, 0xF0, 0x3F, 0xFF, 0xE1, 0xFE,
	0x7F, 0x87, 0xF0, 0x7F, 0x1F, 0x80, 0xFC, 0xFE, 0x03, 0xFB, 0xF0, 0x07,
	0xEF, 0xC0, 0x1F, 0xBF, 0x00, 0x7E, 0xFE, 0x01, 0xF9, 0xF8, 0x0F, 0xF7,
	0xF0, 0x7F, 0xDF, 0xFF, 0xFF, 0x3F, 0xFF, 0xFC, 0x7F, 0xFF, 0xE0, 0xFF,
	0xDF, 0x80, 0xFC, 0x7E, 0x00, 0x01, 0xF8, 0x00, 0x07, 0xE0, 0x00, 0x3F,
	0x80, 0x00, 0xFC, 0x08, 0x07, 0xF0, 0x70, 0x3F, 0x83, 0xFF, 0xFE, 0x1F,
	0xFF, 0xF0, 0x7F, 0xFF, 0x80, 0xFF, 0xFC, 0x01, 0xFF, 0xE0, 0x00, 0xFC,
	0x00 };

const GFXglyph NormalNumbersBoldGlyphs [] PROGMEM = {
	{ 0,  22,  32,  24,    1,  -30 },   // 0x30 '0'
	{ 88,  12,  30,  17,    3,  -29 },   // 0x31 '1'
	{ 133,  22,  31,  24,    1,  -30 },   // 0x32 '2'
	{ 219,  21,  32,  24,    1,  -30 },   // 0x33 '3'
	{ 303,  23,  30,  24,    0,  -29 },   // 0x34 '4'
	{ 390,  21,  32,  24,    1,  -30 },   // 0x35 '5'
	{ 474,  21,  32,  24,    2,  -30 },   // 0x36 '6'
	{ 558,  22,  30,  24,    1,  -29 },   // 0x37 '7'
	{ 641,  22,  32,  24,    1,  -30 },   // 0x38 '8'
	{ 729,  22,  32,  24,    1,  -30 } }; // 0x39 '9'

const GFXfont NormalNumbersBold PROGMEM = {
	(uint8_t  *) NormalNumbersBoldBitmaps,
	(GFXglyph *) NormalNumbersBoldGlyphs,
	0x30, 0x39, 59 };


