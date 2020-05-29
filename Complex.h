// 
// KLASA LICZB ZESPOLONYCH
//
// Obiekty typu complexA sa liczbami zespolonymi w zapisie algebraicznym
// Obiekty typu complexE, to postac wykladnicza
// 
// W klasach zostaly przygotowane konstruktory konwertujace, dzieki czemu przypisanie liczby w postaci wykladniczej do algebraicznej (A = E) powoduje od razu konwersje miedzy tymi typami
// 
// operatory dzialan zostaly przeciazone tak, aby podstawowe operacje na liczbach zespolonych mozna bylo wykonywac za pomoca operatorow +, -, *, /, *=, /= oraz !, ktory sluzy do utworzenia liczby sprzezonej
//
// wartosci kata fazy sa przeliczane w radianach


#pragma once

#include <iostream>
#include <string>
#include <cmath>

const double M_PI = acos(-1);

 class complexE;

///////////////////////////////////////////////////////////////////////////////
//////////////////////// POSTAC ALGEBRAICZNA //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class complexA															// klasa liczby zespolonej w postaci algebraicznej
{
public:

	double r;															// czesc rzeczywista postaci algebraicznej
	double i;															// czesc urojona postaci algebraicznej

	complexA(void);														// Konstruktor domyslny
	complexA(double R, double I);										// Zwykly konstruktor obiektu klasy complex (liczba zespolona)
	complexA(double R);													// todo Konstruktor konwerujacy typ double do typu complex - dzieki temu mozliwe jest rzutowanie typu
	complexA(const complexE& AA);										// Konstruktor konwertujacy postac wykladnicza do algebraicznej

	operator double();													// todo Funkcja konwertujaca do typu wbudowanego

	complexA operator+(complexA B);										// Przeladowanie operatora dodawania
	complexA operator-(complexA B);										// Przeladowanie operatora odejmowania
	complexA operator*(complexA B);										// Przeladowanie operatora mnozenia
	complexA operator/(complexA B);										// Przeladowanie operatora dzielenia
	complexA operator!();												// Przeladowanie operatora negacji (w obecnej sytuacji zwraca on liczbe sprzezona)
	complexA operator*=(complexA A);									// Przeladowanie operatora *=
	complexA operator/=(complexA A);									// Przeladowanie operatora /=

	std::string show();													// Funkcja zwracajaca liczbe w postaci tekstowej
};



////////////////////////////////////////////////////////////////////////////////
//////////////////////// POSTAC WYKLADNICZA ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

class complexE
{
public:

	double z;															// modul liczby zespolonej
	double f;															// faza liczby zespolonej

	complexE(double z, double f);										// Konstruktor liczby zespolonej
	complexE(double z);													// Konstruktor konwerujacy liczbe rzeczywista na zespolona
	complexE(void);														// Konstruktor domyslny
	complexE(const complexA& A);										// Konstruktor konwertujacy postac algebraiczna do wykladniczej

	operator double();

	complexE operator+(complexE B);										// Przeladowanie operatora sumy
	complexE operator-(complexE B);										// Przeladowanie operatora roznicy
	complexE operator*(complexE B);										// Przeladowanie operatora iloczynu
	complexE operator/(complexE B);										// Przeladowanie operatora ilorazu
	complexE operator*=(complexE A);									// Przeladowanie operatora *=
	complexE operator/=(complexE A);									// Przeladowanie operatora /=
	void operator=(complexE A);											// Przeladowanie operatora przypisania

	std::string show();													// Funkcja zwracajaca liczbe w postaci tekstowej
};