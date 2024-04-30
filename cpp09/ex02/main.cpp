#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <sstream>
#include <limits>

int main(int argc, char* argv[]) {
    std::vector<int> vec;
    std::deque<int> deque;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers_string>" << std::endl;
        return 1;
    }

    std::string numbersString(argv[1]);

    if(numbersString.length() == 0){
        std::cerr << "Usage: " << argv[0] << " <numbers_string>" << std::endl;
        return 1;
    }

    std::istringstream iss(numbersString);

    long long int number;
    while (iss >> number) {
        if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min()) {
            std::cerr << "El número está fuera de los límites permitidos para int." << std::endl;
            return 1;
        }
        vec.push_back(static_cast<int>(number));
        deque.push_back(static_cast<int>(number));
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
    clock_t start = clock();
    makerVec.mergeInShort();
    clock_t end = clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "After: ";
    printContainerVEC(makerVec.getContainer(TWO));
    std::cout << std::endl;
    std::cout << "Tiempo transcurrido (ms): " << (duration * 1000) << std::endl;
    std::cout << std::endl;

    std::cout << "DEQ------------------------------------------------------------------------" << std::endl;
    std::cout << "Before: ";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MergeInsortMakerDeque makerDeq(deque);
    start = clock();
    makerDeq.mergeInShort();
    end = clock();
    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "After: ";
    printContainerDEQUE(makerDeq.getContainer(TWO));
    std::cout << std::endl;
    std::cout << "Tiempo transcurrido (ms): " << (duration * 1000) << std::endl;
    std::cout << std::endl;

    return 0;
}