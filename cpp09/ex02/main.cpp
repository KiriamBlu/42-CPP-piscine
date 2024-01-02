#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <chrono>
#include <sstream>
#include <algorithm>



int strToInt(const std::string& str) {
    int result = 0;
    int sign = 1;
    size_t i = 0;

    // Manejar el signo
    if (str[i] == '-') {
        sign = -1;
        ++i;
    } else if (str[i] == '+') {
        ++i;
    }

    for (; i < str.size(); ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            std::cerr << "Error: Carácter no válido en la cadena" << std::endl;
            exit(1);
        }
    }

    return result * sign;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers_string>" << std::endl;
        return 1;
    }

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::milliseconds duration;

    std::string numbersString(argv[1]);
    std::istringstream iss(numbersString);

    std::vector<int> vec;
    std::list<int> lst;
    std::deque<int> deq;

    std::string numberStr;
    while (iss >> numberStr) {
        int number = strToInt(numberStr);
        vec.push_back(number);
        lst.push_back(number);
        deq.push_back(number);
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

    MergeInsortMaker<std::vector<int> > makerVec(vec);
    start = std::chrono::high_resolution_clock::now();
    makerVec.mergeInShort();
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "After: " << makerVec << std::endl;
    std::cout << "Tiempo transcurrido (ms): " << duration.count() << std::endl;
    std::cout << std::endl;

    std::cout << "LIST------------------------------------------------------------------------" << std::endl;
    std::cout << "Before: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MergeInsortMaker<std::list<int> > makerList(lst);
    start = std::chrono::high_resolution_clock::now();
    makerList.mergeInShort();
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "After: " << makerList << std::endl;
    std::cout << "Tiempo transcurrido (ms): " << duration.count() << std::endl;
    std::cout << std::endl;


    std::cout << "DEQ------------------------------------------------------------------------" << std::endl;
    std::cout << "Before: ";
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i] << " ";
    }
    std::cout << std::endl;

    MergeInsortMaker<std::deque<int> > makerDeq(deq);
    start = std::chrono::high_resolution_clock::now();
    makerDeq.mergeInShort();
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "After: " << makerDeq << std::endl;
    std::cout << "Tiempo transcurrido (ms): " << duration.count() << std::endl;
    std::cout << std::endl;


    return 0;
}

