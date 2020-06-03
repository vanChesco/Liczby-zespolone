#include "Complex.h"


std::ostream& operator<<(std::ostream& do_cout, complexA& value)								// Przeladowanie operatora << klasy ostream dla postaci algebraicznej
{
	do_cout << std::to_string(value.r);
	if (value.i < 0) do_cout << " - " << std::to_string(-value.i) << "i";
	else do_cout << " + " << std::to_string(value.i) << "i";

	return do_cout;
}

complexA operator+(complexA A, complexA B)														// Przeladowanie operatora dodawania
{
	complexA sum;

	sum.r = A.r + B.r;
	sum.i = A.i + B.i;

	return sum;
}

complexA operator-(complexA A, complexA B)														// Przeladowanie operatora dodawania
{
	complexA diff;

	diff.r = A.r - B.r;
	diff.i = A.i - B.i;

	return diff;
}

complexA operator*(complexA A, complexA B)														// Przeladowanie operatora mnozenia
{
	complexA mlt;

	mlt.r = A.r * B.r - A.i * B.i;
	mlt.i = A.i * B.r + A.r * B.i;

	return mlt;
}

complexA operator/(complexA A, complexA B)														// Przeladowanie operatora dzielenia
{
	complexA div;

	div.r = (A.r * B.r + A.i * B.i) / (B.r * B.r + B.i * B.i);
	div.i = (A.i * B.r - A.r * B.i) / (B.r * B.r + B.i * B.i);

	return div;
}


std::ostream& operator<<(std::ostream& do_cout, complexE& value)								// Przeladowanie operatora << klasy ostream dla postaci wykladniczej
{
	do_cout << std::to_string(float(value.z)) << "e^" << std::to_string((float)(value.f)) << "i" << " (" << value.f * 180 / M_PI << "*)";

	return do_cout;
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
	complexE diff;

	diff.z = pow(A.z * A.z + B.z * B.z - 2 * A.z * B.z * cos(A.f - B.f), 0.5);
	diff.f = atan((B.z * sin(B.f) - A.z * sin(A.f)) / (A.z * cos(A.f) - B.z * cos(B.f)));

	return diff;
}

complexE operator*(complexE A, complexE B)
{
	complexE mlt;

	mlt.z = A.z * B.z;
	mlt.f = A.f + B.f;

	return mlt;
}

complexE operator/(complexE A, complexE B)
{
	complexE div;

	div.z = A.z / B.z;
	div.f = A.f - B.f;

	return div;
}

/// --------------- \\\\\\\\\\
/// PROGRAM GLOWNY  \\\\\\\\\\
/// --------------- \\\\\\\\\\

int main()
{
	complexA A(8, -14), B(4, 5), sumaA(2, 0), sconv;
	complexE Y, Z(3, -3000*M_PI/180), sumaE(3, 99);

	sumaE =  (complexE)2.0f *Z;
	
	Z = !~Z;

	std::cout << Z << '\n';












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