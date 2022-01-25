// ConsoleApplication20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Wielokat{
public:
//	Wielokat(){};
//	virtual int calc_area(){ return 0; }
//	~Wielokat(){};

	virtual int calc_area() = 0;

	virtual ~Wielokat(){};
};

class Trojkat : public Wielokat{
private:
	int base, height;
public:
	Trojkat(int a, int b) : base(a), height(b){};

	int calc_area(){
		double area = height * base / (double)2;
		return area;
	}

	~Trojkat(){};
};

class Prostokat : public Wielokat{
private:
	int height, base;
public:
	Prostokat(int a, int b) : base(a), height(b){};

	int calc_area(){
		double area = base * height;
		return area;
	}

	~Prostokat(){};
};

class Kwadrat : public Prostokat{
public:
	Kwadrat(int a) :Prostokat(a, a){};
	~Kwadrat(){};
};

double areasum(Wielokat *poly[], int size){
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += poly[i]->calc_area();
	}
	return sum;
}

int main() {

	double dim1 = 2, dim2 = 5;
	int choice;

	std::cout << "Choose the polygon of which the are you want to calculate:\n1.Triangle\n2.Rectangle\n3.Square" << std::endl;
	std::cin >> choice;

	switch (choice){
	case 1:{
			   Trojkat t1(dim1, dim2);
			   int res = t1.calc_area();
			   std::cout << "The area of the triangle is " << res << "\n";;
			   break;
	}
	case 2:{
			   Prostokat t1(dim1, dim2);
			   int res = t1.calc_area();
			   std::cout << "The area of the rectangle is " << res << "\n";;
			   break;
	}
	case 3:{
			   Kwadrat t1(dim1);
			   int res = t1.calc_area();
			   std::cout << "The area of the square is " << res << "\n";
			   break;
	}
	default:
		std::cout << "Okay please choose a correct option next time.";
		break;
	}
	// Wielokat wielokat1; nie mozna utworzyc obiektu abstrakcyjnej klasy wielokat
	Wielokat *poly[3];
	poly[0] = new Trojkat(5, 4);
	poly[1] = new Prostokat(3, 10);
	poly[2] = new Kwadrat(3);

	std::cout << "The area of all the polygons is equal to " << areasum(poly, 3) << std::endl;

	for (auto &&i : poly)
	{
		delete i;
	}

	return 0;
}
