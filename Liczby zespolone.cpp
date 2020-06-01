#include "Complex.h"

int main()
{
	complexA A(8, -14), B(4, 5), sumaA(2, 0), sconv;
	complexE Y, Z(3, 3), sumaE(3, 0);

	Y = A;
	Z = B;

	sumaA = A -= B;
	sconv = sumaE = ~(Y * Z);

	std::cout << sumaA.show() << '\n' << sconv.show() << '\n' << sumaE.show() << "\n\n";










/*
	for (int i=0; i<720; i++)
	{
		sumaE.f+=0.01;
		sconv = sumaE;
		std::cout << i << ": " << sumaE.z << "e^" << sumaE.f << "\t| "<< 180*sumaE.f/M_PI << " | " << "\t=> " << sconv.r << " + i" << sconv.i << "\n";
	}*/

	/*sumaA = A - B;

	Y = A;
	Z = B;

	sumaE = Y - Z;
	sconv = sumaE;

	std::cout << sumaA.show() << "\n\n" << sconv.show() << "\n\n";

	*/











//	complexA C(3, 4), D(4, 5), 
//			suma, iloraz, roznica, iloczyn;

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
	/*
	suma = C + D;																					//todo Dodawanie dwoch liczb zespolonych za pomoca przeladowanego operatora +
	iloraz = C * D;
	roznica = C - D;
	iloczyn = C / D;

	std::cout	<< "\n\n\tWynik sumowania:\t" << suma.show()
				<< "\n\tWynik mnozenia\t\t"	<< iloraz.show()
				<< "\n\tWynik odejmowania\t"	<< roznica.show()
				<< "\n\tWynik dzielenia\t\t " << iloczyn.show() << '\n'
				<< "\n";
*/
	/*int z;
	z = suma;

	std::cout << "\tPo konwersji do int: " << z << "\n\n";*/

/*	
	complexE S(5, atan(4 / 3)), R(pow(41, 0.5), atan(5 / 4)),
		mnozenie, dzielenie;
	
	mnozenie = R;
	dzielenie = S / R;

	std::cout << "\tMnozenie postaci wykladniczej:\t\t" << mnozenie.show() << " " << mnozenie.z*cos(mnozenie.f) << " + i" << mnozenie.z*sin(mnozenie.f) << '\n';
	std::cout << "\tDzielenie postaci wykladniczej:\t\t" << dzielenie.show() << '\n';

//	D = S;
//	std::cout << D.show() << '\n';
	*/
	return 0;
}