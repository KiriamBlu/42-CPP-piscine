
#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <chrono> 


int main() {
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::milliseconds duration;
    std::vector<int> vec;
    std::list<int> lst;
    for (int i = 0; i < 3000; ++i) {
        int number = rand() % 10000;
        vec.push_back(number);
        lst.push_back(number);
    }
    MergeInsortMaker<std::vector<int> > maker(vec);

    std::cout << "VEC----------------------------------------------------------------------" << std::endl;
    
    //std::cout << "Before: " << maker << std::endl;

    start = std::chrono::high_resolution_clock::now();
    maker.mergeInShort();
    end = std::chrono::high_resolution_clock::now();

    std::cout << "---------------------------------------------------------------------------" << std::endl;
 
    std::cout << "After: " << maker << std::endl;

    // Calcular el tiempo transcurrido en milisegundos
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tiempo transcurrido (ms): " << duration.count() << std::endl;

    std::cout << std::endl;


    MergeInsortMaker<std::list<int> > maker2(lst);

    std::cout << "LIST---------------------------------------------------------------------" << std::endl;

    //std::cout << "Before: " << maker2 << std::endl;

    std::cout << "---------------------------------------------------------------------------" << std::endl;

    start = std::chrono::high_resolution_clock::now(); // Registrar el tiempo de inicio
    maker2.mergeInShort();
    end = std::chrono::high_resolution_clock::now(); // Registrar el tiempo de finalización

    std::cout << "---------------------------------------------------------------------------" << std::endl;


    std::cout << "After: " << maker2 << std::endl;

    // Calcular el tiempo transcurrido en milisegundos
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tiempo transcurrido (ms): " << duration.count() << std::endl;

    return 0;
}


