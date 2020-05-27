#include "Complex.h"

int main()
{
	complex C(3, 4), D(4, 5), 
			suma(0, 0), iloraz(0, 0), roznica(0, 0), iloczyn(0, 0);

/*	std::cout << "Liczba pierwsza:\n\nPodaj czesc rzeczywista: ";
	std::cin >> C.r;
	std::cout << "Podaj czesc urojona: ";
	std::cin >> C.i;

	std::cout << "\n\nLiczba druga:\n\nPodaj czesc rzeczywista: ";
	std::cin >> D.r;
	std::cout << "Podaj czesc urojona: ";
	std::cin >> D.i; */

//    suma = sum(C, (complex)4.0f);																	//todo tu nastepuje rzutowanie typu dzieki konstruktorowi konwertujacemu
//
//    //todo rownie dobrze moze tu byc zapis bez uwzglednienia rzutowania, czyli:
//
//    suma = sum(C, 4.0f);
//
//    suma = sum(C, 4);
//
//    suma = multi(C, D);

	suma = C + D;																					//todo Dodawanie dwoch liczb zespolonych za pomoca przeladowanego operatora +
	iloraz = C * D;
	roznica = C - D;
	iloczyn = C / D;

	std::cout	<< "\n\n\tWynik sumowania:\t" << suma.algeb()
				<< "\n\tWynik mnozenia\t\t"	<< iloraz.algeb()
				<< "\n\tWynik odejmowania\t"	<< roznica.algeb()
				<< "\n\tWynik dzielenia\t\t " << iloczyn.algeb() << '\n'
				<< "\n\tPostac wykladnicza\t"	<< C.expon() << '\n'
				<< "\n";

	int z;
	z = suma;

	std::cout << "\tPo konwersji do int: " << z << "\n\n";

	return 0;
}


