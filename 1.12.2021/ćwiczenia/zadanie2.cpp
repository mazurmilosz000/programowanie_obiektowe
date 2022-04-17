// ConsoleApplication21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Pracownik{
private:
	double pensja;
public:
	Pracownik(){};
	Pracownik(double a) : pensja(a){};
	

	double getPensja(){ return pensja; }
	void setPensja(double pensja){ this->pensja = pensja; }

	virtual void przyznaj_bonus(double kwota){
		if (kwota > 0.5*pensja){
			std::cout << "Kwota bonusu zbyt duza, powinna stanowic maksymalnie polowe pensji pracownika." << std::endl;
		}
		else{
			std::cout << "Przyznano pracownikowi bonus o wartosci " << kwota << "." << std::endl;
		}
	}
	virtual ~Pracownik(){};
};

class Stazysta : public Pracownik{
private:
	unsigned int czas_stazu;
public:
	Stazysta(double a, unsigned int b) : Pracownik(a), czas_stazu(b){};
	
	void przyznaj_bonus(double kwota){
		if (czas_stazu > 5 && kwota < getPensja()*0.5){
			std::cout << "Przyznano stazyscie bonus o wartosci " << kwota << "." << std::endl;
		}
		else{
			std::cout << "Nie mozna przydzielic bonusu temu stazyscie." << std::endl;
		}
	}
	~Stazysta(){};
};

class Kierownik : public Pracownik{
private:
	unsigned int liczba_podwladnych;
public:
	Kierownik(double a, unsigned int b) : Pracownik(a), liczba_podwladnych(b){};

	void przyznaj_bonus(double kwota){
		if (kwota <= getPensja()){
			std::cout << "Przyznano kierownikowi bonus o wartosci " << kwota + liczba_podwladnych * 50 << "." << std::endl;
		}
		else{
			std::cout << "Nie mozna przydzielic bonusu temu kierownikowi." << std::endl;
		}
	}
	~Kierownik(){};
};

int main() {

	Pracownik *pracownicy[6];
	pracownicy[0] = new Pracownik(2000);
	pracownicy[1] = new Pracownik(2300);
	pracownicy[2] = new Stazysta(1500, 5);
	pracownicy[3] = new Stazysta(1300, 6);
	pracownicy[4] = new Kierownik(5000, 7);
	pracownicy[5] = new Kierownik(5500, 10);

	/* pracownicy[0]->przyznaj_bonus(1100);
	pracownicy[1]->przyznaj_bonus(1100);
	pracownicy[2]->przyznaj_bonus(400);
	pracownicy[3]->przyznaj_bonus(400);
	pracownicy[4]->przyznaj_bonus(5100);
	pracownicy[5]->przyznaj_bonus(5000); */

	for (auto &&i : pracownicy){
		i->przyznaj_bonus(250);
	}

	for (auto &&i : pracownicy){
		delete i;
	}
	return 0;
}
