/*!
	@file     tm1637.hpp
	@author   Gavin Lyons
	@brief    Header file for for TM1637 module. Model 4
	@note     URL:: https://github.com/gavinlyonsrepo/TM1637_PICO
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "pico/stdlib.h"
#include "tm1637_font_data.hpp"

/*!
	@brief Class for TM1637 Model 4
*/
class TM1637plus_Model4 {

public:

	TM1637plus_Model4 (uint8_t clock, uint8_t data , int delay, int DisplaySize) ;
	void displayBegin(void);
	void displayClose(void);
	void displayClear(void);
	void setBrightness(uint8_t brightness, bool on );

	void setSegments(const uint8_t segments[], uint8_t length , uint8_t pos );
	void DisplayDecimal(int num, bool leading_zero, uint8_t length , uint8_t pos );
	void DisplayDecimalwDot(int num, uint8_t dots , bool leading_zero ,uint8_t length , uint8_t pos );
	void DisplayString(const char* numStr, uint8_t dots , uint8_t length, uint8_t position);
	unsigned char encodeCharacter(unsigned char digit);

protected:

private:

	uint8_t _DATA_IO; /**<  GPIO connected to DIO on Tm1637  */
	uint8_t _CLOCK_IO; /**<  GPIO connected to CLk on Tm1637  */
	uint8_t _DisplaySize = 4; /**< size of display in digits */
	int _BitDelayUS = 75; /**< Us second delay used in communications */
	uint8_t _brightness; /**< Brightness level 0-7*/

	const uint8_t _TM1637_COMMAND_1    = 0x40;   /**< Automatic data incrementing */
	const uint8_t _TM1637_COMMAND_2    = 0xC0;  /**< Data Data1~N: Transfer display data */
	const uint8_t _TM1637_COMMAND_3    = 0x80;  /**< Display intensity */
	const uint8_t _TM1637_ASCII_OFFSET = 0x20;  /**< Offset in the ASCII table for font Start position */

	void CommBitDelay(void);
	void CommStart(void);
	void CommStop(void);
	bool writeByte(uint8_t byte);

};
