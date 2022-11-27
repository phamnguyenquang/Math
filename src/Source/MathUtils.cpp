/*
 * MathUtils.cpp
 *
 *  Created on: 27 Nov 2022
 *      Author: phamn
 */

#include "../Headers/MathUtils.h"
#include "../resources/fparser.cc"

FunctionParser fp;

MathUtils::MathUtils() {
}

double MathUtils::CalculateLimitAt(std::string expression, std::string var,
		double val, bool right) {
	try {
		if (!(expression.find(var) != std::string::npos)) {
			throw -999;
		}
		//get static fa ready
		double variables[1] = { val };
		fp.Parse(expression, var);
		double fa = fp.Eval(variables);

		//try calculate (fx-fa)/(x-a)
		double prevResult = 0;
		double currentResult = 999;
		double xRun = 0;
		double fx = 0;
		if (right) {
			xRun = val + 1000;
			while (abs(currentResult - prevResult)
					>= std::numeric_limits<double>::epsilon() && xRun > val) {

				prevResult = currentResult;
				xRun = (xRun + val) / 2;
				variables[0] = xRun;
				fx = fp.Eval(variables);
				currentResult = (fx - fa) / (xRun - val);

			}
		} else {
			xRun = val - 1000;
			while (abs(currentResult - prevResult)
					>= std::numeric_limits<double>::epsilon() && xRun < val) {

				prevResult = currentResult;
				xRun = (xRun + val) / 2;
				variables[0] = xRun;
				fx = fp.Eval(variables);
				currentResult = (fx - fa) / (xRun - val);

			}
		}
		return currentResult;
	} catch (int number) {
		std::cout << "Invalid Expression" << std::endl;
		return -1;
	}
}

double MathUtils::IntegralSingleVarFunct(std::string expression,
		std::string var, double begin, double end) {
	try {
		if (!(expression.find(var) != std::string::npos)) {
			throw -999;
		}
		if (begin > end) {
			double var = begin;
			begin = end;
			end = var;
		}
		if (begin == end) {
			return 0;
		}
		double prevResult = 0.0;
		double currentResult = 999;

		double newEnd = end;
		double result = 0.0;
		double width = 0.0;
		double heightLeft = 0.0;
		double heightRight = 0.0;
		double step = 0.0;
		//fix left height
		double variables[1] = { 0 };
		fp.Parse(expression, var);
		while (abs(currentResult - prevResult)
				>= std::numeric_limits<double>::epsilon()) {
			result = 0.0;
			step = (newEnd + begin) / (256 + 128 + 64 + 32 + 16 + 8);
			for (double i = begin; i <= end; i += step) {
				//left height
				variables[0] = i;
				heightLeft = fp.Eval(variables);
				//right height
				variables[0] = i + step;
				heightRight = fp.Eval(variables);
				result += (heightLeft + heightRight) * step / 2;
			}
			prevResult = currentResult;
			currentResult = result;
			newEnd = end / 2;
		}
		return currentResult;
	} catch (int number) {
		std::cout << "Invalid Expression" << std::endl;
		return -1;
	}

}

double MathUtils::DerivativeSingleVarFunct(std::string expression,
		std::string var, double value) {
	try {
		double leftLim = MathUtils::CalculateLimitAt(expression, var, value,
				false);
		double rightLim = MathUtils::CalculateLimitAt(expression, var, value,
				true);

		if (abs(rightLim - leftLim) < std::numeric_limits<double>::epsilon()) {
			return rightLim;
		} else {
			throw 101;

		}
	} catch (int number) {
		std::cout
				<< "No derivative exist, returning max negative double possible"
				<< std::endl;
		return -std::numeric_limits<double>::max();
	}

}
