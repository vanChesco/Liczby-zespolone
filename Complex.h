#pragma once
#include <iostream>
#include <string>
#include <cmath>

const double M_PI = acos(-1);

class complex																					// klasa liczby zespolonej
{
public:

	double r;														// czesc rzeczywista postaci algebraicznej
	double i;														// czesc urojona postaci algebraicznej
	double Z = pow(r * r + i * i, 0.5);								// czesc rzeczywista postaci wykladniczej
	double fi = (360 / (2 * M_PI)) * atan((i / r));					// czesc urojona postaci wykladniczej

	complex(double R, double I) : r(R), i(I) {};													// Zwykly konstruktor obiektu klasy complex (liczba zespolona)
	complex(double R) : r(R), i(0) { std::cout << "konwersja\n"; };								// todo Konstruktor konwerujacy typ float do typu complex - dzieki temu mozliwe jest rzutowanie typu

	operator int() 																				// todo Funkcja konwertujaca do typu wbudowanego
	{
		return (int)r;
	};

	complex operator*=(complex A);
	complex operator/=(complex A);

	std::string algeb();
	std::string expon();
};

std::string complex::algeb()
{
	std::string value;

	value = std::to_string(r);
	if (i < 0) value += " - " + std::to_string(-i) + "i";
	else value += " + " + std::to_string(i) + "i";

	return value;
}

std::string complex::expon()
{
	return std::to_string(Z) + " e^" + std::to_string(fi);
}



complex operator+(complex A, complex B)															//todo Przeladowanie operatora dodawania
{
	complex sum(0, 0);

	sum.r = A.r + B.r;
	sum.i = A.i + B.i;

	return sum;
};

complex operator-(complex A, complex B)															//todo Przeladowanie operatora dodawania
{
	complex diff(0, 0);

	diff.r = A.r - B.r;
	diff.i = A.i - B.i;

	return diff;
};

complex operator*(complex A, complex B)															//todo Przeladowanie operatora mnozenia
{
	complex mlt(0, 0);

	mlt.r = A.r * B.r - A.i * B.i;
	mlt.i = A.i * B.r + A.r * B.i;

	return mlt;
}

complex  complex::operator*=(complex A)
{
	complex mlt(r, i);

	mlt.r = A.r * r - A.i * i;
	mlt.i = A.i * r + A.r * i;

	r = mlt.r;
	i = mlt.i;

	return mlt;
}

complex operator/(complex A, complex B)															//todo Przeladowanie operatora dzielenia
{
	complex div(0, 0);

	div.r = (A.r * B.r + A.i * B.i) / (B.r * B.r + B.i * B.i);
	div.i = (A.i * B.r - A.r * B.i) / (B.r * B.r + B.i * B.i);

	return div;
}

complex  complex::operator/=(complex A)
{
	complex div(r, i);

	div.r = (r * A.r + i * A.i) / (A.r * A.r + A.i * A.i);
	div.i = (i * A.r - r * A.i) / (A.r * A.r + A.i * A.i);

	r = div.r;
	i = div.i;

	return div;
}