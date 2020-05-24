#include <iostream>

class complex                               // Agregat do przechowywania skladnikow liczby zespolonej
{
public:

    float r;
    float i;

    complex(float R, float I) : r(R), i(I) {};      // Zwykly konstruktor obiektu klasy complex (liczba zespolona)
    complex(float R) : r(R), i(0) {};               // todo Konstruktor konwerujacy typ float do typu complex
};



complex sum(complex A, complex B)
{
    complex sum(0, 0);

    sum.r = A.r + B.r;
    sum.i = A.i + B.i;

    return sum;
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

    suma = sum(C, 4.0f);

    std::cout << "\n\nWynik sumowania, to: " << suma.r << " + i" << suma.i << "\n\n\n";

    return 0;
}