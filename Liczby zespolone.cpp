﻿#include <iostream>

class complex                               // klasa liczby zespolonej
{
public:

    float r;
    float i;

    complex(float R, float I) : r(R), i(I) {};                                                  // Zwykly konstruktor obiektu klasy complex (liczba zespolona)
    complex(float R) : r(R), i(0) { std::cout << "konwersja\n"; };                              // todo Konstruktor konwerujacy typ float do typu complex - dzieki temu mozliwe jest rzutowanie typu

    operator float() 
    { 
        std::cout << "\nconv\n";                                                                // todo Funkcja konwertujaca do typu wbudowanego
        return (float)r; 
    };
};



complex sum(complex A, complex B)
{
    complex sum(0, 0);

    sum.r = A.r + B.r;
    sum.i = A.i + B.i;

    return sum;
}

complex multi(complex A, complex B)
{
    complex mlt(0, 0);

    mlt.r = A.r * B.r - A.i * B.i;
    mlt.i = A.i * B.r + A.r * B.i;
    
    return mlt;
}

int main()
{
    complex C(0,0), D(0,0), suma(0,0);

    std::cout << "Liczba pierwsza:\n\nPodaj czesc rzeczywista: ";
    std::cin >> C.r;
    std::cout << "Podaj czesc urojona: ";
    std::cin >> C.i;

    std::cout << "\n\nLiczba druga:\n\nPodaj czesc rzeczywista: ";
    std::cin >> D.r;
    std::cout << "Podaj czesc urojona: ";
    std::cin >> D.i;

    suma = sum(C, (complex)4.0f);                                                               //todo tu nastepuje rzutowanie typu dzieki konstruktorowi konwertujacemu

    //todo rownie dobrze moze tu byc zapis bez uwzglednienia rzutowania, czyli:

    suma = sum(C, 4.0f);

    suma = sum(C, 4);

    suma = multi(C, D);

    std::cout << "\n\nWynik sumowania, to: " << suma.r << " + i" << suma.i << "\n\n\n";

    float z;
    z = suma;

    std::cout << "Po konwersji do float: " << z;

    return 0;
}