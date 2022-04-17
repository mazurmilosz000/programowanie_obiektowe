#include <iostream>
#include <fstream>

class abstrakcyjna {
    public:
        abstrakcyjna() {};
		virtual void zapisywanie(std::ofstream &nazwa_pliku) = 0;
		~abstrakcyjna(){};
};

class Prostokat : public abstrakcyjna{
private:
	int height, base;
	
public:
	Prostokat(int a, int b) : base(a), height(b){};

	int calc_area(){
		double area = base * height;
		return area;
	}
	
	void zapisywanie(std::ofstream &nazwa_pliku)
	{
		nazwa_pliku << "prostokat o wymiarach: a = " << base << " i b = " << height << " ma pole wynoszace: " << calc_area() << std::endl; 
	} 
	~Prostokat(){};
};
class ulamek : public abstrakcyjna{
private:
	int nominator, denominator;
	double *dvalue;
public:
	ulamek(int nom, int denom) : nominator(nom), denominator(denom)
	{
		double d = (double)nom/denom;
		dvalue = new double(d);
	}
	void zapisywanie(std::ofstream &nazwa_pliku)
	{
		nazwa_pliku << "ulamek: " << nominator << "/" << denominator << " czyli: " << *dvalue << std::endl;
	}
	~ulamek(){delete dvalue;};
};
int main()
{
	std::ofstream plik;
	plik.open("jedzonko.txt", std::ios::app);
	
	if(plik.is_open())
	{
		std::cout << "Plik zostal otwarty pomyslnie";
	}
	else
	{
		std::cout << "Plik nie zostal otwarty pomyslnie";
	}
	
	Prostokat p1(43,26);
	p1.zapisywanie(plik);
	
	Prostokat p2(12,32);
	p2.zapisywanie(plik);
	
	ulamek u1(3,17);
	u1.zapisywanie(plik);
	
	abstrakcyjna *wypisz[6];
	wypisz[0] = new Prostokat(12,33);
	wypisz[1] = new ulamek(1,2);
	wypisz[2] = new Prostokat(5,7);
	wypisz[3] = new ulamek(3,15);
	wypisz[4] = new Prostokat(21,21);
	wypisz[5] = new ulamek(77,14);

	for (auto &&i : wypisz)
	{
		i->zapisywanie(plik);
	}
	
	for (auto &&i : wypisz)
	{
		delete i;
	}
	
	plik.close();
    return 0;
}

