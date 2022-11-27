/*
 * Token.h
 *
 *  Created on: 27 Nov 2022
 *      Author: phamn
 */

#ifndef HEADERS_TOKEN_H_
#define HEADERS_TOKEN_H_

class Token{
public:
	char kind;
	double value;
	Token(char ch);
	Token(char ch, double val);
};



#endif /* HEADERS_TOKEN_H_ */
