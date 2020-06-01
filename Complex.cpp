#include "Complex.h"


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


complexA::complexA(void) : r(0), i(0) {}
complexA::complexA(double R, double I) : r(R), i(I) {}
complexA::complexA(double R) : r(R), i(0) {}
complexA::complexA(const complexE& AA) : r(AA.z * cos(AA.f)), i(AA.z * sin(AA.f)) {}
complexA::~complexA() {}

complexA::operator int()
{
	return int(r);
}

complexA::operator float()
{
	return float(r);
}

complexA::operator double()
{
	return (double)r;
}

complexA complexA::operator!()																	// operator zwracajacy liczbe sprzezona
{
	complexA bnd;

	bnd.r = r;
	bnd.i = -i;

	return bnd;
}

complexA complexA::operator*=(complexA B)
{
	complexA mlt(r, i);

	r = B.r * r - B.i * i;
	i = B.i * r + B.r * i;

	return *this;
}

complexA complexA::operator/=(complexA B)
{
	r = (r * B.r + i * B.i) / (B.r * B.r + B.i * B.i);
	i = (i * B.r - r * B.i) / (B.r * B.r + B.i * B.i);

	return *this;
}

complexA complexA::operator+=(complexA B)														//todo Przeladowanie operatora dodawania
{
	r = r + B.r;
	i = i + B.i;

	return *this;
}

complexA complexA::operator-=(complexA B)														//todo Przeladowanie operatora dodawania
{
	r = r - B.r;
	i = i - B.i;

	return *this;
}

complexA complexA::operator=(complexA A)
{
	r = A.r;
	i = A.i;

	return *this;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


complexE::complexE(double z, double f) : z(z), f(f) {}
complexE::complexE(double z) : z(z), f(0) {}
complexE::complexE(void) : z(0), f(0) {}
complexE::complexE(const complexA& A) : z(pow(A.r * A.r + A.i * A.i, 0.5)), f(atan(A.i / A.r)) {}
complexE::~complexE() {}

complexE::operator int()
{
	return int(z);
}

complexE::operator float()
{
	return float(z);
}

complexE::operator double()
{
	return (double)z;
}

complexE complexE::operator!()																	// operator zwracajacy liczbe sprzezona
{
	complexE bnd;

	bnd.z = z;
	bnd.f = -f;

	return bnd;
}

complexE complexE::operator~()																	// operator zawezajacy zakres fazy do (0 - 2pi)
{
	complexE rng;
	
	rng.z = z;
	rng.f = fmod(f, (2*M_PI));

	return rng;
}

complexE complexE::operator=(complexE A)														// Operator przypisania
{
	z = A.z;
	f = A.f;

	return *this;									// dzieki temu zwracaniu wartosci mozliwe jest wykonanie operacji wielokrotnego przypisania A=B=C=D
}

complexE complexE::operator^(double n)															// Operator potegowania
{
	complexE pwr;

	pwr.z = pow(z, n);
	pwr.f = n * f;

	return pwr;
}


complexE complexE::operator*=(complexE A)
{
	z = A.z * z;
	f = A.f + f;

	return *this;
}

complexE complexE::operator/=(complexE A)
{
	z = z / A.z;
	f = f - A.f;

	return *this;
}

complexE complexE::operator+=(complexE B)
{
	complexE sum;

	sum.z = pow(z * z + B.z * B.z + 2 * z * B.z * cos(f - B.f), 0.5);
	sum.f = atan((B.z * sin(B.f) + z * sin(f)) / (z * cos(f) + B.z * cos(B.f)));

	z = sum.z;
	f = sum.f;

	return *this;
}

complexE complexE::operator-=(complexE B)
{
	complexE diff;

	diff.z = pow(z * z + B.z * B.z - 2 * z * B.z * cos(f - B.f), 0.5);
	diff.f = atan((B.z * sin(B.f) - z * sin(f)) / (z * cos(f) - B.z * cos(B.f)));

	z = diff.z;
	f = diff.f;

	return *this;
}