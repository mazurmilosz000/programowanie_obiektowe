#include <iostream>
#include <exception>
class TimeRangeException : std::exception
{
public:
	const char* what() { return "Podales nieprawidlowa wartosc"; }
};
class HoursException : public TimeRangeException
{
public:
	//	void show() { std::cout << "Liczba godzin jest mniejsza od zera" << std::endl; }
	const char* what() { return "Liczba godzin jest mniejsza od zera"; }
};
class MinutesException : public TimeRangeException
{
public:
	const char* what() { return "Liczba minut nie nalezy do prawidlowego zakresu"; }
};
class SecondsException : public TimeRangeException
{
public:
	const char* what() { return "Liczba sekund nie nalezy do prawidlowego zakresu"; }
};

int exchange(int h, int m, int s);
int main()
{
	int hours, minutes, seconds, count;

	std::cout << "Podaj godziny: " << std::endl;
	std::cin >> hours;
	std::cout << "Podaj minuty: " << std::endl;
	std::cin >> minutes;
	std::cout << "Podaj sekundy: " << std::endl;
	std::cin >> seconds;

	try
	{
		count = exchange(hours, minutes, seconds);
		std::cout << "Podano: " << hours << "h " << minutes << "m " << seconds << "s " << ", a to jest: " << count << " sekund" << std::endl;
	}
	//catch (HoursException& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//catch (MinutesException& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//catch (SecondsException& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	catch (TimeRangeException& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
int exchange(int h, int m, int s)
{
	int count = 0;
	if (h < 0)
		throw HoursException();

	if (m < 0 || m > 59)
		throw MinutesException();

	if (s < 0 || s > 59)
		throw SecondsException();
	count += (h * 3600);
	count += (m * 60);
	count += s;

	return count;
}