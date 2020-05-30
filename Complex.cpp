#include "Complex.h"


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


complexA::complexA(void) : r(0), i(0) {};
complexA::complexA(double R, double I) : r(R), i(I) {};
complexA::complexA(double R) : r(R), i(0) {};
complexA::complexA(const complexE& AA) : r(AA.z * cos(AA.f)), i(AA.z * sin(AA.f)) {};

complexA::operator double()
{
	return (double)r;
}

complexA complexA::operator!()																	//todo operator zwracajacy liczbe sprzezona
{
	complexA bound;

	bound.r = r;
	bound.i = -i;

	return bound;
}

complexA complexA::operator+(complexA B)														//todo Przeladowanie operatora dodawania
{
	complexA sum;

	sum.r = r + B.r;
	sum.i = i + B.i;

	return sum;
}

complexA complexA::operator-(complexA B)														//todo Przeladowanie operatora dodawania
{
	complexA diff;

	diff.r = r - B.r;
	diff.i = i - B.i;

	return diff;
}

complexA complexA::operator*(complexA B)														//todo Przeladowanie operatora mnozenia
{
	complexA mlt;

	mlt.r = r * B.r - i * B.i;
	mlt.i = i * B.r + r * B.i;

	return mlt;
}

complexA complexA::operator/(complexA B)														//todo Przeladowanie operatora dzielenia
{
	complexA div;

	div.r = (r * B.r + i * B.i) / (B.r * B.r + B.i * B.i);
	div.i = (i * B.r - r * B.i) / (B.r * B.r + B.i * B.i);

	return div;
}

complexA complexA::operator*=(complexA A)
{
	complexA mlt(r, i);

	mlt.r = A.r * r - A.i * i;
	mlt.i = A.i * r + A.r * i;

	r = mlt.r;
	i = mlt.i;

	return mlt;
}

complexA complexA::operator/=(complexA A)
{
	complexA div(r, i);

	div.r = (r * A.r + i * A.i) / (A.r * A.r + A.i * A.i);
	div.i = (i * A.r - r * A.i) / (A.r * A.r + A.i * A.i);

	r = div.r;
	i = div.i;

	return div;
}

std::string complexA::show()
{
	std::string value;

	value = std::to_string(r);
	if (i < 0) value += " - " + std::to_string(-i) + "i";
	else value += " + " + std::to_string(i) + "i";

	return value;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


complexE::complexE(double z, double f) : z(z), f(f) {};
complexE::complexE(double z) : z(z), f(0) {};
complexE::complexE(void) : z(0), f(0) {};
complexE::complexE(const complexA& A) : z(pow(A.r * A.r + A.i * A.i, 0.5)), f(atan(A.i / A.r)) {};

complexE::operator double()
{
	return (double)z;
}

complexE complexE::operator!()																	//todo operator zwracajacy liczbe sprzezona
{
	complexE bound;

	bound.z = z;
	bound.f = -f;

	return bound;
}

complexE complexE::operator~()																	// operator zawezajacy zakres fazy do (0 - 2pi)
{
	complexE bound;

	bound.z = z;
	bound.f = fmod(f, (2*M_PI));

	return bound;
}

void complexE::operator=(complexE A)
{
	z = A.z;
	f = A.f;
}

complexE complexE::operator/(complexE B)
{
	complexE div;

	div.z = z / B.z;
	div.f = f - B.f;

	return div;
}

complexE complexE::operator+(complexE B)
{
	complexE sum;

	sum.z = pow(z * z + B.z * B.z + 2 * z * B.z * cos(f - B.f), 0.5);
	sum.f = atan((B.z * sin(B.f) + z * sin(f)) / (z * cos(f) + B.z * cos(B.f)));

	return sum;
}

complexE complexE::operator-(complexE B)
{
	complexE sum;

	sum.z = pow(z * z + B.z * B.z - 2 * z * B.z * cos(f - B.f), 0.5);
	sum.f = atan((B.z * sin(B.f) - z * sin(f)) / (z * cos(f) - B.z * cos(B.f)));

	return sum;
}

complexE complexE::operator*(complexE B)
{
	complexE mlt;

	mlt.z = z * B.z;
	mlt.f = f + B.f;

	return mlt;
}

complexE complexE::operator*=(complexE A)
{
	complexE mlt;

	mlt.z = A.z * z;
	mlt.f = A.f + f;

	z = mlt.z;
	f = mlt.f;

	return mlt;
}

complexE complexE::operator/=(complexE A)
{
	complexE div;

	div.z = z / A.z;
	div.f = f - A.f;

	z = div.z;
	f = div.f;

	return div;
}

std::string complexE::show()
{
	return std::to_string(float(z)) + " e^" + std::to_string((float)f);
}