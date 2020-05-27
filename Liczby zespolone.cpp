#include "Complex.h"

int main()
{
	complexA C(3, 4), D(4, 5), 
			suma, iloraz, roznica, iloczyn;

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

	std::cout	<< "\n\n\tWynik sumowania:\t" << suma.show()
				<< "\n\tWynik mnozenia\t\t"	<< iloraz.show()
				<< "\n\tWynik odejmowania\t"	<< roznica.show()
				<< "\n\tWynik dzielenia\t\t " << iloczyn.show() << '\n'
				<< "\n\tPostac wykladnicza\t"	<< C.show() << '\n'
				<< "\n";

	int z;
	z = suma;

	std::cout << "\tPo konwersji do int: " << z << "\n\n";


	complexE S(3, 4), R(4, 5),
		mnozenie, dzielenie;

	mnozenie = S * R;
	dzielenie = S / R;

	std::cout << "\tMnozenie postaci wykladniczej:\t\t" << mnozenie.show() << '\n';
	std::cout << "\tDzielenie postaci wykladniczej:\t\t" << dzielenie.show() << '\n';

//	D = S;
//	std::cout << D.show() << '\n';
	
	return 0;
}


