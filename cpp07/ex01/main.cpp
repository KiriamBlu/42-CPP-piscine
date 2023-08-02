
#include "iter.hpp"

void increment(int& num){
    num++;
}


template <typename T>
void doubleNumber(T& num){
    num *= 2;
}

template <typename T>
void printItem(T item){
    std::cout << item << " ";
}

int main(){
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    int intArrayLength = sizeof(intArray) / sizeof(int);
    double doubleArrayLength = sizeof(doubleArray) / sizeof(double);
    char charArrayLength = sizeof(charArray) / sizeof(char);

    std::cout << "intArray: ";
    ::iter(intArray, intArrayLength, increment);
    for (int i = 0; i < intArrayLength; ++i)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;

    std::cout << "doubleArray: ";
    ::iter(doubleArray, doubleArrayLength, doubleNumber<double>);
    for (int i = 0; i < doubleArrayLength; ++i)
        std::cout << doubleArray[i] << " ";
    std::cout << std::endl;

    std::cout << "charArray: ";
    ::iter(charArray, charArrayLength, printItem<char>);
    std::cout << std::endl;

    std::cout << "doubleArray: ";
    ::iter(doubleArray, doubleArrayLength, printItem<double>);
    std::cout << std::endl;

    std::cout << "intArray: ";
    ::iter(intArray, intArrayLength, printItem<double>);
    std::cout << std::endl;

    return 0;
}