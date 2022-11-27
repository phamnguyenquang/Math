/*
 ============================================================================
 Name        : Math.cpp
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <iostream>
#include<cmath>
#include<vector>
#include <Source/MathUtils.cpp>

int main(void) {
	std::string exp = "x^2";
	std::string Zgaussian = "(exp((x^2)/2))/(sqrt(2*3.1416))";
//	FunctionParser fp;
//	fp.Parse(exp, "x");
//	double var[1]={3.0};
//	double testRes=fp.Eval(var);
//	double testRes = MathUtils::DerivativeSingleVarFunct(exp, "x", 3.0);
	double testRes = MathUtils::IntegralSingleVarFunct(Zgaussian, "x",-100, 100);
	std::cout<<testRes<<std::endl;
}
