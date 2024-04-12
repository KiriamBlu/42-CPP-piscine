#include "PmergeMe.hpp"

//------------------------------------------------------------VECTOR---------------------------------------------------------------//
size_t powerOfTwo(size_t exponent);
void printContainerLONGVEC(const std::vector<long int>& cont);

MergeInsortMakerVec::MergeInsortMakerVec(std::vector<int> contenedor) : _contenedor(contenedor) {
    begin(ONE);
    begin(TWO);
}

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
    insertAlg(ONE, vec);
    std::cout << "1 ";
    printContainerVEC(getContainer(ONE));
    std::cout << "S ";
    printContainerVEC(getContainer(TWO));
    std::cout << "VECTOR EXTRA:\n";
    printContainerLONGVEC(vec);
}

void MergeInsortMakerVec::merge(size_t threshold, int container, size_t lap) {
    std::vector<int>& auxContainer = getContainer(OTHER(container));

    if (lap >= threshold)
        return;

    int package[2] = {getNumber(lap + 1, container), getNumber(lap, container)};
    merge(threshold, container, lap + 2);
    int pos = (package[0] > package[1]) ? lap + 1 : lap;
    int number = (package[0] < package[1]) ? package[1] : package[0];
    package[0] = (package[0] < package[1]) ? package[0] : package[1];
    package[1] =  number; 

    auxContainer.insert(auxContainer.begin(), number);

    insertNumberInPos(pos, 0, container, DELETE);
    return ;
}

void MergeInsortMakerVec::fixSecuencies(int container) {
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
    std::vector<int>::iterator beginIterator = getBegin(container);
    std::vector<int>::iterator endIterator = getEnd(container);

    for (std::vector<int>::iterator it = beginIterator; it != endIterator; ++it) {
        vec.push_back(*it);
    }
}

void MergeInsortMakerVec::groupSwapper(int container){
    std::vector<int>& auxContainer = getContainer(container);
    size_t swapper[2] = {2, 2};
    size_t threshold;
    size_t i = 0;
    size_t lap = 2;
    uint8_t last = 0;

    while (swapper[1] <= auxContainer.size()){
        threshold = swapper[1] / 2;
        i += threshold;

        for (size_t j = 0;  j < threshold; j++){
            std::swap(auxContainer[i - threshold + j ], auxContainer[(i + threshold - j) - 1]);
        }
        i += threshold;
        swapper[1] = powerOfTwo(lap) - swapper[0];
        swapper[0] = swapper[1];
        lap++;
        if ( i + swapper[1] > auxContainer.size() && last == 0){
            swapper[1] = auxContainer.size() - i;
            last = 1;
        }
    }
}

void MergeInsortMakerVec::insertAlg(int container, std::vector<long int> &vec){
    std::vector<int>& auxContainer = getContainer(container);
    std::vector<int>& auxContainer2 = getContainer(OTHER(container));
    std::vector<int>::iterator bend;
    std::vector<int>::iterator aux;
    std::vector<long int>::iterator vecIter;
    int value;
    int pair;

    while(auxContainer.size()){
        value = getNumber(0, container); 
        insertNumberInPos(0, 0, container, DELETE);

        vecIter = std::find(vec.begin(), vec.end(), value);

        bend = auxContainer2.end();

        if(vecIter != vec.end()){
            pair = *vecIter;
            bend = std::find(auxContainer2.begin(), auxContainer2.end(), value);
        }

        aux = binarySearch(vec, value, auxContainer2.begin(), bend);

        size_t vecPos = std::distance(auxContainer2.begin(), aux);
        vecIter = vec.begin() + vecPos;

        vec.insert(vecIter, 0xFFFFFFFF); 
        auxContainer2.insert(aux, value);
    }
}


std::vector<int>::iterator MergeInsortMakerVec::binarySearch(std::vector<long int> &vec, int value, std::vector<int>::iterator start, std::vector<int>::iterator end) {
    int comparativeValue;
    std::vector<int>::iterator comparativePos;

    comparativePos = start;
    std::advance(comparativePos, std::distance(start, end) / 2);
    comparativeValue = *comparativePos;

    if (start == end)
        return comparativePos;

    if (comparativeValue == value)
        return comparativePos;

    if (*comparativePos > value)
        return binarySearch(vec, value, start, comparativePos);
    else
        return binarySearch(vec, value, ++comparativePos, end);
}

int MergeInsortMakerVec::getNumber(size_t position, int container) {

    while (position != getItPos(container)) {
        next((position < getItPos(container)) ? PREV : NEXT, container);
    }
    return *getCurrent(container);
}

void MergeInsortMakerVec::insertNumberInPos(size_t pos, int num, int container, int flag) {
    int direction = static_cast<int>(pos) - static_cast<int>(getItPos(container));

    while (pos != getItPos(container)){
        next((direction < 0) ? PREV : NEXT, container);
    }
    insert(num, container, flag);

}


void MergeInsortMakerVec::insert(int num, int container, int flag) {
    std::vector<int>& auxContainer = getContainer(container);
    std::vector<int>::iterator& auxIterator = (container == ONE) ? _current1 : _current2;

    if (flag != DELETE) {
        if (auxIterator == getBegin(container)) {
            auxContainer.insert(auxIterator, num);
        } else {
            auxIterator = auxContainer.insert(auxIterator, num);
        }
    } else {
        std::vector<int>::iterator temp = auxIterator;
        if (auxIterator != getEnd(container)) {
            auxIterator = auxContainer.erase(temp);
        } else {
            auxContainer.pop_back();
            auxIterator = getEnd(container) - 1;
        }
        getCurrent(container) = auxIterator;
    }
}


void MergeInsortMakerVec::begin(int container) {
    getCurrent(container) = (container == ONE) ? _contenedor.begin() : _contenedor2.begin();
    getItPos(container) = 0;
}

void MergeInsortMakerVec::next(int direction, int container) {
    std::vector<int>::iterator& auxIterator = (container == ONE) ? _current1 : _current2;
    size_t& auxNumPos = (container == ONE) ? _itPos1 : _itPos2;

    if (direction == NEXT) {
        ++auxIterator;
        ++auxNumPos;
    } else if (direction == PREV) {
        --auxIterator;
        --auxNumPos;
    }
}

std::vector<int>& MergeInsortMakerVec::getContainer(int container) {
    return (container == ONE) ? _contenedor : _contenedor2;
}

size_t MergeInsortMakerVec::size(int container) {
    return (container == ONE) ? _contenedor.size() : _contenedor2.size();
}

std::vector<int>::iterator& MergeInsortMakerVec::getCurrent(int container) {
    return (container == ONE) ? _current1 : _current2;
}

size_t& MergeInsortMakerVec::getItPos(int container) {
    return (container == ONE) ? _itPos1 : _itPos2;
}

std::vector<int>::iterator MergeInsortMakerVec::getBegin(int container) {
    return (container == ONE) ? _contenedor.begin() : _contenedor2.begin();
}

std::vector<int>::iterator MergeInsortMakerVec::getEnd(int container) {
    return (container == ONE) ? _contenedor.end() : _contenedor2.end();
}

void MergeInsortMakerVec::printContent(std::ostream& os, int container)  {
    os << "MergeInsortMakerVec Content: ";
    std::vector<int>& cont = getContainer(container);
    for (std::vector<int>::const_iterator it = cont.begin(); it != cont.end(); ++it) {
        os << *it << " ";
    }
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

size_t powerOfTwo(size_t exponent) {
    size_t result = 1;
    for (size_t i = 0; i < exponent; ++i) {
        result *= 2;
    }
    return result;
}

//------------------------------------------------------------DEQUE---------------------------------------------------------------//


size_t powerOfTwo(size_t exponent);
void printContainerLONGDEQUE(const std::deque<long int>& cont);

MergeInsortMakerDeque::MergeInsortMakerDeque(std::deque<int> contenedor) : _contenedor(contenedor) {
    begin(ONE);
    begin(TWO);
}

void MergeInsortMakerDeque::mergeInShort() {
    std::deque<long int> vec;
    size_t length = size(ONE);

    merge((length % 2) == 0 ? length : length - 1, ONE);
    fixSequences(ONE);
    getPairs(vec, ONE);
    getContainer(TWO).insert(getBegin(TWO),vec[0]);
    getContainer(ONE).erase(getBegin(ONE));
    vec.insert(vec.begin(), 0xFFFFFFFF);
    groupSwapper(ONE);
    insertAlg(ONE, vec);
}

void MergeInsortMakerDeque::merge(size_t threshold, int container, size_t lap) {
    if (lap >= threshold)
        return;

    std::deque<int>& auxContainer = getContainer(OTHER(container));

    int package[2] = {getNumber(lap + 1, container), getNumber(lap, container)};
    merge(threshold, container, lap + 2);
    int pos = (package[0] > package[1]) ? lap + 1 : lap;
    int number = (package[0] < package[1]) ? package[1] : package[0];
    package[0] = std::min(package[0], package[1]);
    package[1] = number;

    auxContainer.push_front(number);

    insertNumberInPos(pos, 0, container, DELETE);
}

void MergeInsortMakerDeque::fixSequences(int container) {
    std::deque<int>& one = getContainer(container);
    std::deque<int>& S = getContainer(OTHER(container));

    for (size_t i = 0; i + 1 < S.size(); i++) {
        if (S[i + 1] < S[i]) {
            std::swap(S[i], S[i + 1]);
            std::swap(one[i], one[i + 1]);

            if (i > 0)
                i -= 2;
        }
    }
}

void MergeInsortMakerDeque::getPairs(std::deque<long int> &vec, int container) {
    std::deque<int>::iterator beginIterator = getBegin(container);
    std::deque<int>::iterator endIterator = getEnd(container);
    for (std::deque<int>::iterator it = beginIterator; it != endIterator; ++it)
        vec.push_back(*it);
}


void MergeInsortMakerDeque::groupSwapper(int container) {
    std::deque<int>& auxContainer = getContainer(container);
    size_t swapper[2] = {2, 2};
    size_t threshold;
    size_t i = 0;
    size_t lap = 2;
    uint8_t last = 0;

    while (swapper[1] <= auxContainer.size()) {
        threshold = swapper[1] / 2;
        i += threshold;

        for (size_t j = 0;  j < threshold; j++) {
            std::swap(auxContainer[i - threshold + j], auxContainer[(i + threshold - j) - 1]);
        }
        i += threshold;
        swapper[1] = powerOfTwo(lap) - swapper[0];
        swapper[0] = swapper[1];
        lap++;
        if (i + swapper[1] > auxContainer.size() && last == 0) {
            swapper[1] = auxContainer.size() - i;
            last = 1;
        }
    }
}


void MergeInsortMakerDeque::insertAlg(int container, std::deque<long int> &vec){
    std::deque<int>& auxContainer = getContainer(container);
    std::deque<int>& auxContainer2 = getContainer(OTHER(container));
    std::deque<int>::iterator bend;
    std::deque<int>::iterator aux;
    std::deque<long int>::iterator vecIter;
    int value;
    int pair;

    while(auxContainer.size()){
        value = getNumber(0, container); 
        insertNumberInPos(0, 0, container, DELETE);

        vecIter = std::find(vec.begin(), vec.end(), value);

        bend = auxContainer2.end();

        if(vecIter != vec.end()){
            pair = *vecIter;
            bend = std::find(auxContainer2.begin(), auxContainer2.end(), value);
        }

        aux = binarySearch(vec, value, auxContainer2.begin(), bend);

        size_t vecPos = std::distance(auxContainer2.begin(), aux);
        vecIter = vec.begin() + vecPos;

        vec.insert(vecIter, 0xFFFFFFFF); 
        auxContainer2.insert(aux, value);
    }
}

std::deque<int>::iterator MergeInsortMakerDeque::binarySearch(std::deque<long int> &vec, int value, std::deque<int>::iterator start, std::deque<int>::iterator end) {
    int comparativeValue;
    std::deque<int>::iterator comparativePos;

    comparativePos = start;
    std::advance(comparativePos, std::distance(start, end) / 2);
    comparativeValue = *comparativePos;

    if (start == end)
        return comparativePos;

    if (comparativeValue == value)
        return comparativePos;

    if (*comparativePos > value)
        return binarySearch(vec, value, start, comparativePos);
    else
        return binarySearch(vec, value, ++comparativePos, end);
}


int MergeInsortMakerDeque::getNumber(size_t position, int container) {

    while (position != getItPos(container)) {
        next((position < getItPos(container)) ? PREV : NEXT, container);
    }
    return *getCurrent(container);
}

void MergeInsortMakerDeque::insertNumberInPos(size_t pos, int num, int container, int flag) {
    int direction = static_cast<int>(pos) - static_cast<int>(getItPos(container));

    while (pos != getItPos(container)){
        next((direction < 0) ? PREV : NEXT, container);
    }
    insert(num, container, flag);

}


void MergeInsortMakerDeque::insert(int num, int container, int flag) {
    std::deque<int>& auxContainer = getContainer(container);
    std::deque<int>::iterator& auxIterator = (container == ONE) ? _current1 : _current2;

    if (flag != DELETE) {
        if (auxIterator == getBegin(container)) {
            auxContainer.insert(auxIterator, num);
        } else {
            auxIterator = auxContainer.insert(auxIterator, num);
        }
    } else {
        std::deque<int>::iterator temp = auxIterator;
        if (auxIterator != getEnd(container)) {
            auxIterator = auxContainer.erase(temp);
        } else {
            auxContainer.pop_back();
            auxIterator = getEnd(container) - 1;
        }
        getCurrent(container) = auxIterator;
    }
}


void MergeInsortMakerDeque::begin(int container) {
    getCurrent(container) = (container == ONE) ? _contenedor.begin() : _contenedor2.begin();
    getItPos(container) = 0;
}

void MergeInsortMakerDeque::next(int direction, int container) {
    std::deque<int>::iterator& auxIterator = (container == ONE) ? _current1 : _current2;
    size_t& auxNumPos = (container == ONE) ? _itPos1 : _itPos2;

    if (direction == NEXT) {
        ++auxIterator;
        ++auxNumPos;
    } else if (direction == PREV) {
        --auxIterator;
        --auxNumPos;
    }
}

std::deque<int>& MergeInsortMakerDeque::getContainer(int container) {
    return (container == ONE) ? _contenedor : _contenedor2;
}

size_t MergeInsortMakerDeque::size(int container) {
    return (container == ONE) ? _contenedor.size() : _contenedor2.size();
}

std::deque<int>::iterator& MergeInsortMakerDeque::getCurrent(int container) {
    return (container == ONE) ? _current1 : _current2;
}

size_t& MergeInsortMakerDeque::getItPos(int container) {
    return (container == ONE) ? _itPos1 : _itPos2;
}

std::deque<int>::iterator MergeInsortMakerDeque::getBegin(int container) {
    return (container == ONE) ? _contenedor.begin() : _contenedor2.begin();
}

std::deque<int>::iterator MergeInsortMakerDeque::getEnd(int container) {
    return (container == ONE) ? _contenedor.end() : _contenedor2.end();
}

void MergeInsortMakerDeque::printContent(std::ostream& os, int container)  {
    os << "MergeInsortMakerDeque Content: ";
    std::deque<int>& cont = getContainer(container);
    for (std::deque<int>::const_iterator it = cont.begin(); it != cont.end(); ++it) {
        os << *it << " ";
    }
}
void printContainerDEQUE(const std::deque<int>& cont) {
    std::cout << "Container: ";
    for (size_t i = 0; i < cont.size(); ++i) {
        std::cout << cont[i] << " ";
    }
    std::cout << "\n";
}

void printContainerLONGDEQUE(const std::deque<long int>& cont) {
    std::cout << "Container: ";
    for (size_t i = 0; i < cont.size(); ++i) {
        if(cont[i] != 0xFFFFFFFF)
            std::cout << cont[i] << " ";
        else
            std::cout << "X ";
    }
    std::cout << "\n";
}