#include "Complex.h"


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

complexA operator/(complexA A, complexA B)											//todo Przeladowanie operatora dzielenia
{
	complexA div;

	div.r = (A.r * B.r + A.i * B.i) / (B.r * B.r + B.i * B.i);
	div.i = (A.i * B.r - A.r * B.i) / (B.r * B.r + B.i * B.i);

	return div;
}


void complexE::operator=(complexE A)
{
	z = A.z;
	f = A.f;
}


complexE operator/(complexE A, complexE B)
{
	complexE div;

	div.z = A.z / B.z;
	div.f = A.f - B.f;

	return div;
}


complexE operator+(complexE A, complexE B)
{
	complexE sum;

	sum.z = pow(A.z * A.z + B.z * B.z + 2 * A.z * B.z * cos(A.f - B.f), 0.5);
	sum.f = atan((B.z * sin(B.f) + A.z * sin(A.f)) / (A.z * cos(A.f) + B.z * cos(B.f)));

	return sum;
}

complexE operator-(complexE A, complexE B)
{
	complexE sum;

	sum.z = pow(A.z * A.z + B.z * B.z - 2 * A.z * B.z * cos(A.f - B.f), 0.5);
	sum.f = atan((B.z * sin(B.f) - A.z * sin(A.f)) / (A.z * cos(A.f) - B.z * cos(B.f)));

	return sum;
}
complexE operator*(complexE A, complexE B)
{
	complexE mlt;

	mlt.z = A.z * B.z;
	mlt.f = A.f + B.f;

	return mlt;
}

int main()
{
	complexA A(8, 14), B(4,5), sumaA, sconv;
	complexE Y, Z, sumaE;

	sumaA = A - B;

	Y = A;
	Z = B;

	sumaE = Y - Z;
	sconv = sumaE;

	std::cout << sumaA.show() << "\n\n" << sconv.show() << "\n\n";













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