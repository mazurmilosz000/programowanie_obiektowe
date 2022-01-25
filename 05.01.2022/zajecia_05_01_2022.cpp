#include <iostream>

class Fraction
{
private: 
	int nominator, denominator;
	double* dvalue;

public:
	Fraction(int nom, int denom) : nominator(nom), denominator(denom)
	{
		double dbl = (double)nom / denom;
		dvalue = new double(dbl);
	};

	~Fraction()
	{
		delete dvalue;
	};

	Fraction& operator=(Fraction& arg)
	{
		if (this == &arg)
			return *this;

		this->nominator = arg.nominator;
		this->denominator = arg.denominator;
		delete this->dvalue;
		this->dvalue = arg.dvalue;

		return *this;
	}

	operator double()
	{
		return *this->dvalue;
	}

	friend std::ostream& operator<<(std::ostream&, Fraction&);
	friend std::istream& operator>>(std::istream&, Fraction&);

};

std::ostream& operator<<(std::ostream& output, Fraction& frac)
{
	output << "Fraction: " << frac.nominator << "/" << frac.denominator << "(" << (double)frac << ")" << std::endl;
	return output;
}

std::istream& operator>>(std::istream& input, Fraction& frac)
{
	input >> frac.nominator;
	input >> frac.denominator;
	delete frac.dvalue;
	frac.dvalue = new double((double)frac.nominator / frac.denominator);
	return input;
}

int main(int argc, char const* argv[])
{
	Fraction f1(3, 8);
	std::cin >> f1;
	std::cout << f1;


	return 0;
}