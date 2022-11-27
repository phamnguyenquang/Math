/*
 * Complex
 *
 *  Created on: 27 Nov 2022
 *      Author: phamn
 */

#ifndef HEADERS_COMPLEX_H_
#define HEADERS_COMPLEX_H_


#include<string>

class Complex {
private:
	double real;
	double imagine;
	double calculate_abs();
	double calculate_modulo();

public:
	Complex(double re, double img);
	Complex();
	void set_real(double re);
	void set_img(double img);
	double get_real();
	double get_img();
	double get_abs();
	double get_mod();
	Complex get_conjugate();
	Complex operator+(const Complex& other);
	Complex operator-(const Complex& other);
	Complex operator*(const Complex& other);
	Complex operator/(const Complex& other);
	Complex operator^(const int& other);
	std::string get_representation();
};


#endif /* HEADERS_COMPLEX_H_ */
