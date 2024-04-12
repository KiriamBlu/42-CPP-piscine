#include "PmergeMe.hpp"

void MergeInsortMakerVec::mergeInShort() {
    std::vector<long int> vec;
    size_t length = size(ONE);

    std::cout << "MERGE\n";
    merge((length % 2) == 0 ? length : length - 1, ONE);
    std::cout << "1 ";
    printContainerVEC(getContainer(ONE));
    std::cout << "S ";
    printContainerVEC(getContainer(TWO));
    std::cout << "VECTOR EXTRA:\n";
    printContainerLONGVEC(vec);

    std::cout << "FIX\n";
    fixSecuencies(ONE);
    std::cout << "1 ";
    printContainerVEC(getContainer(ONE));
    std::cout << "S ";
    printContainerVEC(getContainer(TWO));
    std::cout << "VECTOR EXTRA:\n";
    printContainerLONGVEC(vec);

    std::cout << "PAIRS\n";
    getPairs(vec, ONE);
    std::cout << "1 ";
    printContainerVEC(getContainer(ONE));
    std::cout << "S ";
    printContainerVEC(getContainer(TWO));
    std::cout << "VECTOR EXTRA:\n";
    printContainerLONGVEC(vec);

    std::cout << "PASS\n";
    getContainer(TWO).insert(getBegin(TWO),vec[0]);
    getContainer(ONE).erase(getBegin(ONE));
    vec.insert(vec.begin(), 0xFFFFFFFF);
    std::cout << "1 ";
    printContainerVEC(getContainer(ONE));
    std::cout << "S ";
    printContainerVEC(getContainer(TWO));
    std::cout << "VECTOR EXTRA:\n"; 
    printContainerLONGVEC(vec);

    std::cout << "SWAPPER\n";
    groupSwapper(ONE);
     std::cout << "1 ";
    printContainerVEC(getContainer(ONE));
    std::cout << "S ";
    printContainerVEC(getContainer(TWO));
    std::cout << "VECTOR EXTRA:\n";
    printContainerLONGVEC(vec);

    std::cout << "INSERT\n";
    insert(ONE, vec);
    std::cout << "1 ";
    printContainerVEC(getContainer(ONE));
    std::cout << "S ";
    printContainerVEC(getContainer(TWO));
    std::cout << "VECTOR EXTRA:\n";
    printContainerLONGVEC(vec);
}

void MergeInsortMakerVec::merge(size_t threshold, int container, size_t lap) {
    if (lap >= threshold)
        return;

    std::vector<int>& auxContainer = getContainer(OTHER(container));
    int package[2] = {getNumber(lap + 1, container), getNumber(lap, container)};
    merge(threshold, container, lap + 2);
    int pos = (package[0] > package[1]) ? lap + 1 : lap;
    int number = (package[0] < package[1]) ? package[1] : package[0];
    package[0] = std::min(package[0], package[1]);
    package[1] = number;

    auxContainer.insert(auxContainer.begin(), number);
    insertNumberInPos(pos, 0, container, DELETE);
}

void MergeInsortMakerVec::fixSequences(int container) {
    std::vector<int>& one = getContainer(container);
    std::vector<int>& S = getContainer(OTHER(container));

    for (size_t i = 0; i + 1 < S.size(); i++) {
        if (S[i + 1] < S[i]) {
            std::swap(S[i], S[i + 1]);
            std::swap(one[i], one[i + 1]);
            if (i > 0)
                i -= 2;
        }
    }
}

void MergeInsortMakerVec::getPairs(std::vector<long int> &vec, int container) {
    vec.clear();
    std::vector<int>& cont = getContainer(container);
    for (int num : cont)
        vec.push_back(num);
}

void MergeInsortMakerVec::movePairs(int container, std::vector<long int> &vec) {
    std::vector<int>& auxContainer = getContainer(OTHER(container));
    auxContainer.insert(auxContainer.begin(), vec.begin(), vec.end());
    getContainer(container).clear();
}

void MergeInsortMakerVec::groupSwapper(int container) {
    std::vector<int>& auxContainer = getContainer(container);
    size_t lap = 2;
    size_t size = auxContainer.size();
    size_t swapper[2] = {2, 2};
    uint8_t last = 0;

    for (size_t i = 0; swapper[1] <= size; ++i) {
        size_t threshold = swapper[1] / 2;
        size_t index = i * threshold * 2;
        if (index >= size) break;

        for (size_t j = 0; j < threshold; ++j) {
            std::swap(auxContainer[index + j], auxContainer[index + threshold * 2 - j - 1]);
        }

        swapper[1] = powerOfTwo(lap) - swapper[0];
        swapper[0] = swapper[1];
        lap++;
        if (index + swapper[1] > size && last == 0) {
            swapper[1] = size - index;
            last = 1;
        }
    }
}


std::vector<int>& MergeInsortMakerVec::getContainer(int container) {
    return (container == ONE) ? _contenedor : _contenedor2;
}


size_t powerOfTwo(size_t exponent) {
    size_t result = 1;
    for (size_t i = 0; i < exponent; ++i) {
        result *= 2;
    }
    return result;
}

void printContainerVEC(const std::vector<int>& cont) {
    std::cout << "Container: ";
    for (size_t i = 0; i < cont.size(); ++i) {
        std::cout << cont[i] << " ";
    }
    std::cout << "\n";
}

void printContainerLONGVEC(const std::vector<long int>& cont) {
    std::cout << "Container: ";
    for (size_t i = 0; i < cont.size(); ++i) {
        if(cont[i] != 0xFFFFFFFF)
            std::cout << cont[i] << " ";
        else
            std::cout << "X ";
    }
    std::cout << "\n";
}