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
	std::string exp = "exp(x)";
//	FunctionParser fp;
//	fp.Parse(exp, "x");
//	double var[1]={3.0};
//	double testRes=fp.Eval(var);
	double testRes = MathUtils::DerivativeSingleVarFunct(exp, "x", 3.0);
//	double testRes = MathUtils::IntegralSingleVarFunct(exp, "x",3, 3);
	std::cout<<testRes<<std::endl;
}
