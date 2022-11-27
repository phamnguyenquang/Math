/*
 * MathUtils.h
 *
 *  Created on: 27 Nov 2022
 *      Author: phamn
 */

#ifndef HEADERS_MATHUTILS_H_
#define HEADERS_MATHUTILS_H_

#include<string>

class MathUtils {
public:
	static double CalculateLimitAt(std::string expression, std::string var,
			double val, bool right);
	MathUtils();
	static double IntegralSingleVarFunct(std::string expression,
			std::string var, double begin, double end);
	static double DerivativeSingleVarFunct(std::string expression,
			std::string var, double value);
};

#endif /* HEADERS_MATHUTILS_H_ */
