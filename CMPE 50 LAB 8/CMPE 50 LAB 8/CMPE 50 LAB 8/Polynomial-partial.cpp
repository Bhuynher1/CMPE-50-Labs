#include <iostream>
#include <cmath>
#include "polynomial.h"
using namespace std;


Polynomial::Polynomial()
{
	degree = 10;
	coeff = new double[degree + 1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}

Polynomial::Polynomial(int degr)
{
	degree = degr;
	coeff = new double[degree + 1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}

Polynomial::Polynomial(const Polynomial& poly)
{
	degree = poly.get_degree();
	coeff = new double[degree + 1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = poly.get_coeff(i);
	}
}

Polynomial::Polynomial(double cf[], int deg)
{
	degree = deg;
	coeff = new double[degree + 1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = cf[i];
	}
}

Polynomial::~Polynomial()
{
	delete[] coeff;
}

int Polynomial::get_degree() const
{
	return degree;
}

double Polynomial::get_coeff(int deg) const
{
	if (degree < deg)
	{
		return 0;
	}
	return coeff[deg];
}

void Polynomial::set_coeff(int degr, double val)
{
	if (degree < degr)
	{
		cout << "Degree exceeded." << endl;
		return;
	}
	coeff[degr] = val;
}

double Polynomial::evaluate(double val)
{
	double result = 0;
	for (int i = 0; i <= degree; i++)
	{
		result = result + coeff[i] * pow(val, i);
	}
	return result;
}

void Polynomial::operator =(const Polynomial& poly)
{
	if (this == &poly) {
		return;
	}
	degree = poly.get_degree();
	delete[] coeff;
	coeff = new double[degree + 1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = poly.get_coeff(i);
	}
	return;
}

Polynomial operator+(const Polynomial& pola, const Polynomial& polb)
{
	int degrA = pola.get_degree();
	int degrB = polb.get_degree();
	int max_degr;
	if (degrA > degrB) {
		max_degr = degrA;
	}
	else {
		max_degr = degrB;
	}
	Polynomial result(max_degr);
	int i;
	for (i = 0; i <= degrA && i <= degrB; i++) {
		double ans = pola.get_coeff(i) + polb.get_coeff(i);
		result.set_coeff(i, ans);
	}

	for (; i <= max_degr; i++)
	{
		if (degrA != max_degr)
		{
			result.set_coeff(i, polb.get_coeff(i));
		}
		else
		{
			result.set_coeff(i, pola.get_coeff(i));
		}
	}
	return result;
}

Polynomial operator-(const Polynomial& polya, const Polynomial& polyb)
{
	int max_degree;
	int i = 0;
	if (polya.get_degree() > polyb.get_degree())
	{
		max_degree = polya.get_degree();
	}
	else {
		max_degree = polyb.get_degree();
	}
	Polynomial result(max_degree);
	for (i = 0; i <= polya.get_degree() && i <= polyb.get_degree(); i++)
	{
		result.set_coeff(i, polya.get_coeff(i) - polyb.get_coeff(i));
	}
	for (i = 0; i <= max_degree; i++)
	{
		if (max_degree == polya.get_degree())
		{
			result.set_coeff(i, polya.get_coeff(i));
		}
		else {
			result.set_coeff(i, -polyb.get_coeff(i));
		}
	}
	return result;
}

Polynomial operator*(const Polynomial& polya, const Polynomial& polyb)
{
	int degree_a = polya.get_degree();
	int degree_b = polyb.get_degree();
	int max_degree = degree_a + degree_b;
	Polynomial result(max_degree);
	for (int i = 0; i <= degree_b; i++)
	{
		for (int j = 0; j <= degree_a; j++)
		{
			double ans = polyb.get_coeff(i) * polya.get_coeff(j) + result.get_coeff(i + j);
			result.set_coeff(i + j, ans);
		}
	}
	return result;
}

Polynomial operator+(const Polynomial& polya, const int b)
{
	Polynomial result(polya.get_degree());
	for (int i = 0; i < polya.get_degree() + 1; i++)
	{
		if (i == 0)
		{
			result.set_coeff(i, polya.get_coeff(i) + b);
		}
		else {
			result.set_coeff(i, polya.get_coeff(i));
		}
	}
	return result;
}

Polynomial operator-(const Polynomial& polya, const int b)
{
	double cfb[1];
	cfb[0] = b;
	Polynomial polyb(cfb, 0);
	return polya - polyb;
}

Polynomial operator*(const Polynomial& polya, const int b)
{
	int degree_a = polya.get_degree();
	Polynomial result(degree_a);
	for (int i = 0; i <= degree_a; i++)
	{
		result.set_coeff(i, b * polya.get_coeff(i));
	}
	return result;
}

Polynomial operator+(const int a, const Polynomial& polyb)
{
	double cfa[1];
	cfa[0] = static_cast<double>(a);
	Polynomial polya(cfa, 0);
	return polya + polyb;
}

Polynomial operator-(const int a, const Polynomial& polyb)
{
	double cfa[1];
	cfa[0] = a;
	Polynomial polya(cfa, 0);
	return polya - polyb;
}

Polynomial operator*(const int a, const Polynomial& polyb)
{
	int degree_b = polyb.get_degree();
	Polynomial result(degree_b);
	for (int i = 0; i <= degree_b; i++)
	{
		result.set_coeff(i, a * polyb.get_coeff(i));
	}
	return result;
}

ostream& operator << (ostream& ost, const Polynomial& pol)
{
	int degr = pol.get_degree();
	for (int i = degr; 0 <= i; i--)
	{
		cout << pol.get_coeff(i) << "*x^" << i << " ";
		if (i > 0) {
			cout << "+ ";
		}
	}
	return ost;
}

