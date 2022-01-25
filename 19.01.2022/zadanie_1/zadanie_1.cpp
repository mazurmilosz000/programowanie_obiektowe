#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* array;
    int size;
public:
    Array(int size)                         //konstruktor domyslny
    {
        array = new T[size];                //alokacja tablicy dynamicznej
        this->size = size;
    }
    Array(T* array, int n)                  //konstruktor parametrowy
    {
        this->array = array;
        this->size = n;
    }
    Array(const Array& arr1)                //konstruktor kopiujacy
    {
        array = new T[arr1.size];
        size = arr1.size;
        for (int i = 0; i < size; i++) {
            array[i] = arr1.array[i];
        }
    }
    ~Array()
    {
        delete[] array;
    }
    T& operator=(T x)
    {
        return array[x];
    }
    T& operator[](int x)
    {
        if (x < 0 || x >= size)
            throw std::out_of_range("Error! Out of range");
            
        return array[x];
    }
};
int main()
{
    Array<int>  array1(7);
    Array<double>   array2(5);
    Array<std::string> array4(6);


    array1[4] = 3;
    array2[3] = 2.5;
    array4[2] = "dom";
    std::cout << array1[4] << std::endl;
    std::cout << array2[3] << std::endl;
    Array<int> array3(array1);
    std::cout << array3[4] << std::endl;
    std::cout << array4[2] << std::endl;
    try
    {
        std::cout << array1[8] << std::endl;
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}