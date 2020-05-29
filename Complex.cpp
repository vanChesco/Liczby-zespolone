#include "Complex.h"

complexA::complexA(void) : r(0), i(0) {};
complexA::complexA(double R, double I) : r(R), i(I) {};
complexA::complexA(double R) : r(R), i(0) {};
complexA::complexA(const complexE& AA) : r(AA.z* cos(AA.f)), i(AA.z * sin(AA.f)) {};

complexA::operator double()
{
	return (double)r;
};


std::string complexA::show()
{
	std::string value;

	value = std::to_string(r);
	if (i < 0) value += " - " + std::to_string(-i) + "i";
	else value += " + " + std::to_string(i) + "i";

	return value;
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

complexA  complexA::operator/=(complexA A)
{
	complexA div(r, i);

	div.r = (r * A.r + i * A.i) / (A.r * A.r + A.i * A.i);
	div.i = (i * A.r - r * A.i) / (A.r * A.r + A.i * A.i);

	r = div.r;
	i = div.i;

	return div;
}





complexE::complexE(double z, double f) : z(z), f(f) {};
complexE::complexE(double z) : z(z), f(0) {};
complexE::complexE(void) : z(0), f(0) {};
complexE::complexE(const complexA& A) : z(pow(A.r * A.r + A.i * A.i, 0.5)), f(atan(A.i / A.r)) {};

complexE::operator float()
{
	return (float)z;
};


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
	return std::to_string(z) + " e^" + std::to_string(f);
}