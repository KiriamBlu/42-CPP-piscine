#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <sstream>
#include <algorithm>

int main(int argc, char* argv[]) { // PROBAR MAX INT
    std::vector<int> vec;
    std::list<int> list;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers_string>" << std::endl;
        return 1;
    }

    std::string numbersString(argv[1]);
    std::istringstream iss(numbersString);
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::milliseconds duration;

    long long int number;
    while (iss >> number) {
        if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min()) {
            std::cerr << "El número está fuera de los límites permitidos para int." << std::endl;
            return 1;
        }
        vec.push_back(static_cast<int>(number));
        list.push_back(static_cast<int>(number));
        if (iss.peek() == ' ') {
            iss.ignore();
        }
    }

    std::cout << "VEC------------------------------------------------------------------------" << std::endl;
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;


    MergeInsortMakerVec makerVec(vec);
    start = std::chrono::high_resolution_clock::now();
    makerVec.mergeInShort();
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tiempo transcurrido (ms): " << duration.count() << std::endl;
    std::cout << std::endl;

    // std::cout << "LIST------------------------------------------------------------------------" << std::endl;
    // std::cout << "Before: ";
    // for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // MergeInsortMakerList makerList(list);
    // start = std::chrono::high_resolution_clock::now();
    // makerList.mergeInShort();
    // end = std::chrono::high_resolution_clock::now();
    // duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // std::cout << "Tiempo transcurrido (ms): " << duration.count() << std::endl;
    // std::cout << std::endl;


}