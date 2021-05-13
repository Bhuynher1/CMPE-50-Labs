#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Complex {
private:
	double real;
	double imaginary;

public:
	Complex(double real_num, double imaginary_num);

	Complex(double real_num);

	Complex(const Complex& input);

	Complex();

	~Complex();

	double getReal();

	double getImaginary();

	void setReal(double real_num);

	void setImaginary(double imaginary_num);

	//Function op
	bool operator==(Complex& input);

	Complex operator+(Complex input);

	Complex operator-(Complex input);

	Complex operator*(Complex input);

	// I/O functions
	friend istream& operator >>(istream& in, Complex& input);
	friend ostream& operator <<(ostream& out, Complex& input);

	string toString();
};

#endif