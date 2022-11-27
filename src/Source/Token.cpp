/*
 * Token.cpp
 *
 *  Created on: 27 Nov 2022
 *      Author: phamn
 */

#include "../Headers/Token.h"

	Token::Token(char ch): kind(ch), value(0){}
	Token::Token(char ch, double val): kind(ch), value(val){}


