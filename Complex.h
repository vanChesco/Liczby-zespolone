#pragma once
#include <iostream>
#include <string>
#include <cmath>

const double M_PI = acos(-1);
class complexE;


//todo///////////////////////////////////////////////////////////////////////////////////////////////////
//todo////////////////////// POSTAC ALGEBRAICZNA ////////////////////////////////////////////////////////
//todo///////////////////////////////////////////////////////////////////////////////////////////////////

class complexA																	// klasa liczby zespolonej
{
public:

	double r;																	// czesc rzeczywista postaci algebraicznej
	double i;																	// czesc urojona postaci algebraicznej
//	double Z = pow(r * r + i * i, 0.5);											// czesc rzeczywista postaci wykladniczej
//	double fi = (360 / (2 * M_PI)) * atan((i / r));								// czesc urojona postaci wykladniczej

	complexA(void) : r(0), i(0) {};												// Konstruktor domyslny
	complexA(double R, double I) : r(R), i(I) {};								// Zwykly konstruktor obiektu klasy complex (liczba zespolona)
	complexA(double R) : r(R), i(0) { std::cout << "konwersja\n"; };			// todo Konstruktor konwerujacy typ float do typu complex - dzieki temu mozliwe jest rzutowanie typu
	complexA(const complexE& AA) : r(AA.z * tan(AA.f)), i(AA.z / tan(AA.f)) {};

//	friend complexE::complexE(complexA& A);

	operator int() 																// todo Funkcja konwertujaca do typu wbudowanego
	{
		return (int)r;
	};

	complexA operator*=(complexA A);
	complexA operator/=(complexA A);

	std::string show();
};

//complexA::complexA(const complexE& A)
//{
//	r = A.z *tan(A.f);
//	i = A.z / tan(A.f);
//};

std::string complexA::show()
{
	std::string value;

	value = std::to_string(r);
	if (i < 0) value += " - " + std::to_string(-i) + "i";
	else value += " + " + std::to_string(i) + "i";

	return value;
}


complexA operator+(complexA A, complexA B)											//todo Przeladowanie operatora dodawania
{
	complexA sum;

	sum.r = A.r + B.r;
	sum.i = A.i + B.i;

	return sum;
};

complexA operator-(complexA A, complexA B)											//todo Przeladowanie operatora dodawania
{
	complexA diff;

	diff.r = A.r - B.r;
	diff.i = A.i - B.i;

	return diff;
};

complexA operator*(complexA A, complexA B)											//todo Przeladowanie operatora mnozenia
{
	complexA mlt;

	mlt.r = A.r * B.r - A.i * B.i;
	mlt.i = A.i * B.r + A.r * B.i;

	return mlt;
}

complexA  complexA::operator*=(complexA A)
{
	complexA mlt(r, i);

	mlt.r = A.r * r - A.i * i;
	mlt.i = A.i * r + A.r * i;

	r = mlt.r;
	i = mlt.i;

	return mlt;
}

complexA operator/(complexA A, complexA B)											//todo Przeladowanie operatora dzielenia
{
	complexA div;

	div.r = (A.r * B.r + A.i * B.i) / (B.r * B.r + B.i * B.i);
	div.i = (A.i * B.r - A.r * B.i) / (B.r * B.r + B.i * B.i);

	return div;
}

complexA  complexA::operator/=(complexA A)
{
	complexA div(r, i);

	div.r = (r * A.r + i * A.i) / (A.r * A.r + A.i * A.i);
	div.i = (i * A.r - r * A.i) / (A.r * A.r + A.i * A.i);

	r = div.r;
	i = div.i;

	return div;
}



//todo///////////////////////////////////////////////////////////////////////////////////////////////////
//todo////////////////////// POSTAC WYKLADNICZA /////////////////////////////////////////////////////////
//todo///////////////////////////////////////////////////////////////////////////////////////////////////

class complexE
{
public:

	double z;															// modul liczby zespolonej
	double f;															// faza liczby zespolonej

	complexE(double z, double f) : z(z), f(f) {};						// Konstruktor liczby zespolonej
	complexE(double z) : z(z), f(0) {};									// Konstruktor konwerujacy liczbe rzeczywista na zespolona
	complexE(void) : z(0), f(0) {};
//	complexE(complexA& A);

	friend complexA::complexA(const complexE& AA);

	complexE operator*=(complexE A);									// przeladowanie operatora
	complexE operator/=(complexE A);									// przeladowanie operatora
	void operator=(complexE A);											// przeladowanie operatora


	std::string show();
};

//complexE::complexE(complexA& A) : z(pow(A.r* A.r + A.i * A.i, 0.5)), f(A.i/A.r) {}

//complexE operator+(complexE A, complexE B)


complexE operator*(complexE A, complexE B)
{
	complexE mlt;

	mlt.z = A.z * B.z;
	mlt.f = A.f + B.f;

	return mlt;
}

complexE complexE::operator*=(complexE A)
{
	complexE mlt;

	mlt.z = A.z * z;
	mlt.f = A.f + f;

	z = mlt.z;
	f = mlt.f;

	return mlt;
}

complexE operator/(complexE A, complexE B)
{
	complexE div;

	div.z = A.z / B.z;
	div.f = A.f - B.f;

	return div;
}

complexE complexE::operator/=(complexE A)
{
	complexE div;

	div.z = z / A.z;
	div.f = f - A.f;

	z = div.z;
	f = div.f;

	return div;
}

void complexE::operator=(complexE A)
{
	z = A.z;
	f = A.f;
}

std::string complexE::show()
{
	return std::to_string(z) + " e^" + std::to_string(f);
}