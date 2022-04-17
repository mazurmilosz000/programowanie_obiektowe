#include <iostream>
#include <fstream>
#include <string>

int main()
{
    //std::string text;
    std::ifstream MyFile("plik.txt");
    char character;
    int count = 0;
    //int i;

    //while (std::getline(MyFile, text))
    //{
    //    std::cout << text << std::endl;
    //    count += text.length();
    //}
    //while (MyFile)
    //{
    //    MyFile.get(character);
    //    i = character;
    //    if (((i > 63 && i < 91) || (i > 96 && i < 123)))
    //        count++;

    //}
    while (MyFile)
    {
        MyFile.get(character);
        if (isalpha(character))
            count++;

    }
    std::cout << "Ilosc liter w tekscie to: " << count << std::endl;

    

    MyFile.close();
    return 0;

}
