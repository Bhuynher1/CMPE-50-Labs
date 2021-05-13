#include <iostream>
#include <sstream>
#include <cmath>
#include "Complex.h"
using namespace std;

Complex::Complex(double real_num, double imaginary_num) {
	real = real_num;
	imaginary = imaginary_num;
}

Complex::Complex(double real_num) {
	real = real_num;
	imaginary = 0;
}

Complex::Complex(const Complex& input) {
	real = input.real;
	imaginary = input.imaginary;
}

Complex::Complex() {
	real = 1;
	imaginary = 0;
}
Complex::~Complex() {

}

double Complex::getReal() {
	return real;
}

double Complex::getImaginary() {
	return imaginary;
}

void Complex::setReal(double real_num) {
	real = real_num;
}

void Complex::setImaginary(double imaginary_num) {
	imaginary = imaginary_num;
}

bool Complex::operator==(Complex& input) {
	if ((getReal() == input.getReal()) && (getImaginary() == input.getImaginary())) {
		return true;
	}
	else {
		return false;
	}
}

Complex Complex::operator+(Complex input) {
	Complex res;
	res.setReal(getReal() + input.getReal());
	res.setImaginary(getImaginary() + input.getImaginary());
	return res;
}

Complex Complex::operator-(Complex input) {
	Complex res;
	res.setReal(getReal() - input.getReal());
	res.setImaginary(getImaginary() - input.getImaginary());
	return res;
}

Complex Complex::operator*(Complex input) {
	Complex res;
	res.setReal(getReal() * input.getReal() - getImaginary() * input.getImaginary());
	res.setImaginary(getReal() * input.getImaginary() + getImaginary() * input.getReal());
	return res;
}

istream& operator>> (istream& in, Complex& input) {
	cout << "Please enter the real number value: ";
	in >> input.real;
	cout << "Please enter the imaginary number value: ";
	in >> input.imaginary;
	return in;
}

ostream& operator<< (ostream& out, Complex& input) {
	out << "(" << input.real << " + " << input.imaginary << "i)";
	return out;
}

string Complex::toString() {
	stringstream ss1;
	ss1 << getReal();
	string result = ss1.str();
	if (getImaginary() > 0) {
		result += " + ";
	}
	else {
		result += " - ";
	}

	stringstream ss2;
	ss2 << abs(getImaginary());
	result += ss2.str() + "i";
	return result;
}