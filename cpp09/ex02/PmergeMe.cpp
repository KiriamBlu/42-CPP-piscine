#include "PmergeMe.hpp"

MergeInsortMakerVec::MergeInsortMakerVec(std::vector<int> contenedor) : _contenedor(contenedor) {
    begin(ONE);
    begin(TWO);
}

void MergeInsortMakerVec::mergeInShort() {
    size_t length = size(ONE);

    merge((length % 2 == 0) ? length : length - 1, ONE);
    // insert();
}

void MergeInsortMakerVec::merge(size_t threshold, int container, size_t lap) {
    std::vector<int>& auxContainer = getContainer(OTHER(container));

    if (lap >= threshold)
        return;

    merge(threshold, container, lap + 2);
    int package[2] = {getNumber(lap + 1, container), getNumber(lap, container)};
    int pos = (package[0] < package[1]) ? lap : lap + 1;
    int number = (package[0] > package[1]) ? package[1] : package[0];
    package[0] = (package[0] < package[1]) ? package[0] : package[1];
    package[1] =  number; 

    if (auxContainer.empty()) {
        auxContainer.push_back(package[0]);
        auxContainer.push_back(package[1]);
        insertNumberInPos(pos, 0, container, DELETE);
        insertNumberInPos(pos, 0, container, DELETE);
        return;
    }

    std::vector<int>::iterator it = auxContainer.begin();
    while (it != auxContainer.end() && *it < number) {
        ++it;
    }

    if (it != auxContainer.end()) {
        auxContainer.insert(it, number);
    } else {
        auxContainer.push_back(number);
    }

    insertNumberInPos(pos, 0, OTHER(container), DELETE);

    printContainer(auxContainer);
}

std::vector<int>::iterator MergeInsortMakerVec::binarySearch(int value, int index, std::vector<int>::iterator start, std::vector<int>::iterator end, int container) {
    int comparativeValue;
    std::vector<int>::iterator comparativePos;
    size_t var;

    comparativePos = start;
    var = std::distance(getBegin(container), start);
    for (size_t i = 0; i < (size_t)std::distance(start, end) / 2; ++i) {
        ++comparativePos;
        ++var;
    }
    comparativeValue = getNumber(var, container);

    if (start == end)
        return comparativePos;

    if (comparativeValue == value)
        return comparativePos;

    if (comparativeValue > value)
        return binarySearch(value, index, start, comparativePos, container);
    else
        return binarySearch(value, index, ++comparativePos, end, container);
}

int MergeInsortMakerVec::getNumber(size_t position, int container) {
    while (position != getItPos(container)) {
        next((position < getItPos(container)) ? PREV : NEXT, container);
    }
    return *getCurrent(container);
}

void MergeInsortMakerVec::insertNumberInPos(size_t pos, int num, int container, int flag) {
    int direction = static_cast<int>(pos) - static_cast<int>(getItPos(container));

    while (pos != getItPos(container))
        next((direction < 0) ? PREV : NEXT, container);

    insert(num, container, flag);
}

void MergeInsortMakerVec::insert(int num, int container, int flag) {
    std::vector<int>& auxContainer = getContainer(container);
    std::vector<int>::iterator auxIterator;
    size_t* auxNumPos;

    if (container == ONE) {
        auxIterator = _current1;
        auxNumPos = &_itPos1;
    } else {
        auxIterator = _current2;
        auxNumPos = &_itPos2;
    }

    if (flag != DELETE) {
        auxIterator = auxContainer.insert(auxIterator, num);
        ++(*auxNumPos);
    } else {
        if (auxIterator != getBegin(container)) {
            std::vector<int>::iterator temp = auxIterator;
            next(NEXT, container);
            auxContainer.erase(temp); // Corregir aquí
            --(*auxNumPos);
        }
    }
}


void MergeInsortMakerVec::begin(int container) {
    getCurrent(container) = (container == ONE) ? _contenedor.begin() : _contenedor2.begin();
    getItPos(container) = 0;
}

void MergeInsortMakerVec::next(int direction, int container) {
    std::vector<int>::iterator& auxIterator = (container == ONE) ? _current1 : _current2;
    size_t* auxNumPos = (container == ONE) ? &_itPos1 : &_itPos2;

    if (direction == NEXT && auxIterator != getEnd(container)) {
        ++auxIterator;
        ++(*auxNumPos);
    } else if (direction == PREV && auxIterator != getBegin(container)) {
        --auxIterator;
        --(*auxNumPos);
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

void printContainer(const std::vector<int>& cont) {
    std::cout << "Container: ";
    for (size_t i = 0; i < cont.size(); ++i) {
        std::cout << cont[i] << " ";
    }
    std::cout << "\n";
}
