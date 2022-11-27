/*
 * Complex.cpp
 *
 *  Created on: 27 Nov 2022
 *      Author: phamn
 */

#include "../Headers/Complex.h"
#include<cmath>

double Complex::calculate_abs() {
	return std::sqrt(real * real + imagine * imagine);
}
double Complex::calculate_modulo() {
	return std::atan(imagine / real);
}

Complex::Complex(double re, double img) {
	real = re;
	imagine = img;
}
Complex::Complex() {
	real = imagine = 0;
}

void Complex::set_real(double re) {
	real = re;
}
void Complex::set_img(double img) {
	imagine = img;
}
double Complex::get_abs() {
	return Complex::calculate_abs();
}
double Complex::get_mod() {
	return Complex::calculate_modulo();
}

double Complex::get_real() {
	return real;
}
double Complex::get_img() {
	return imagine;
}

Complex Complex::get_conjugate() {
	return Complex(real, -imagine);
}

Complex Complex::operator+(const Complex &other) {
	double new_real = this->real + other.real;
	double new_img = this->imagine + other.imagine;
	return Complex(new_real, new_img);
}
Complex Complex::operator-(const Complex &other) {
	double new_real = real - other.real;
	double new_img = imagine - other.imagine;
	return Complex(new_real, new_img);
}
Complex Complex::operator*(const Complex &other) {
	double new_real = this->real * other.real - this->imagine * other.imagine;
	double new_img = this->real * other.imagine + this->imagine * other.real;
	return Complex(new_real, new_img);
}
Complex Complex::operator/(const Complex &other) {
	double re = other.real;
	double im = other.imagine;
	double denom = re * re + im * im;
	double new_real = (this->real * other.real - this->imagine * other.imagine)
			/ denom;
	double new_img = (this->real * other.imagine + this->imagine * other.real)
			/ denom;
	return Complex(new_real, new_img);
}
Complex Complex::operator^(const int &other) {
	Complex result = Complex(1, 0);
	for (int i = 0; i < other; ++i) {
		result = result * (*this);
	}
	return result;
}
std::string Complex::get_representation() {
	std::string rep = std::to_string(real) + "+" + std::to_string(imagine)
			+ "i";
	return rep;
}
