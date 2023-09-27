
#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <chrono> // Para medir el tiempo

// ... (tu código MergeInsortMaker)

int main() {
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::milliseconds duration;
    // Crear un vector con elementos aleatorios
    std::vector<int> vec;
    for (int i = 0; i < 100; ++i) {
        vec.push_back(rand() % 10000); // Números aleatorios entre 0 y 9999
    }
/*
    MergeInsortMaker<std::vector<int> > maker(vec);

    std::cout << "Before: " << maker << std::endl;

    std::cout << "---------------------------------------------------------------------------" << std::endl;

    start = std::chrono::high_resolution_clock::now(); // Registrar el tiempo de inicio
    maker.mergeInShort();
    end = std::chrono::high_resolution_clock::now(); // Registrar el tiempo de finalización

    std::cout << "---------------------------------------------------------------------------" << std::endl;
 
    std::cout << "After: " << maker << std::endl;

    // Calcular el tiempo transcurrido en milisegundos
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tiempo transcurrido (ms): " << duration.count() << std::endl;
*/
    // Repite el proceso para la lista
    std::list<int> lst;
    for (int i = 0; i < 300; ++i) {
        lst.push_back(rand() % 10000); // Números aleatorios entre 0 y 9999
    }

    MergeInsortMaker<std::list<int> > maker2(lst);

    std::cout << "---------------------------------------------------------------------------" << std::endl;

    std::cout << "Before: " << maker2 << std::endl;

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


