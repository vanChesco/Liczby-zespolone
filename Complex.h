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

	complexA(void);																// Konstruktor domyslny
	complexA(double R, double I);												// Zwykly konstruktor obiektu klasy complex (liczba zespolona)
	complexA(double R);															// todo Konstruktor konwerujacy typ float do typu complex - dzieki temu mozliwe jest rzutowanie typu
	complexA(const complexE& AA);

//	friend complexE::complexE(const complexA& A);

	operator double();																// todo Funkcja konwertujaca do typu wbudowanego


	complexA operator*=(complexA A);
	complexA operator/=(complexA A);

	std::string show();
};



//todo///////////////////////////////////////////////////////////////////////////////////////////////////
//todo////////////////////// POSTAC WYKLADNICZA /////////////////////////////////////////////////////////
//todo///////////////////////////////////////////////////////////////////////////////////////////////////

class complexE
{
public:

	double z;															// modul liczby zespolonej
	double f;															// faza liczby zespolonej

	complexE(double z, double f);										// Konstruktor liczby zespolonej
	complexE(double z);													// Konstruktor konwerujacy liczbe rzeczywista na zespolona
	complexE(void);
	complexE(const complexA& A);

//	friend complexA::complexA(const complexE& AA);
	operator double();

	complexE operator*=(complexE A);									// przeladowanie operatora
	complexE operator/=(complexE A);									// przeladowanie operatora
	void operator=(complexE A);											// przeladowanie operatora


	std::string show();
};

