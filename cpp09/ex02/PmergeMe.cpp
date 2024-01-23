#include "PmergeMe.hpp"

MergeInsortMakerVec::MergeInsortMakerVec(std::vector<int> contenedor) : _contenedor(contenedor) {
    begin(ONE);
    begin(TWO);
}

void MergeInsortMakerVec::mergeInShort() {
    size_t length = size(ONE);

    merge(length, ONE);
    
    insert(ONE);

    std::cout << "Sali\n";
}

void MergeInsortMakerVec::insert(int container){
    std::vector<int>& auxContainer = getContainer(container);
    std::vector<int>& auxContainer2 = getContainer(OTHER(container));
    std::vector<int>::iterator aux;
    int value;

    while(auxContainer.size()){
        value = getNumber(0, container); 
        auxContainer.pop_back();
        aux = binarySearch(value, getBegin(OTHER(container)), getEnd(OTHER(container)), OTHER(container));
        auxContainer2.insert(aux, value);
    }
}

void MergeInsortMakerVec::merge(size_t threshold, int container, size_t lap) {
    std::vector<int>& auxContainer = getContainer(OTHER(container));

    if (lap >= threshold)
        return;

    int package[2] = {getNumber(lap + 1, container), getNumber(lap, container)};
    merge(threshold, container, lap + 2);
    int pos = (package[0] < package[1]) ? lap + 1 : lap;
    int number = (package[0] > package[1]) ? package[1] : package[0];
    package[0] = (package[0] > package[1]) ? package[0] : package[1];
    package[1] =  number; 

    if (auxContainer.empty()) {
        auxContainer.push_back(package[1]);
        auxContainer.push_back(package[0]);
        insertNumberInPos(lap, 0, container, DELETE);
        insertNumberInPos(lap, 0, container, DELETE);
        std::cout << "1:\n";
        printContainer(getContainer(ONE));
        std::cout << "2:\n";
        printContainer(getContainer(TWO));
        return;
    }

    std::vector<int>::iterator it = auxContainer.begin();
    while (*it < number) {
        ++it;
        if(it == auxContainer.end())
            break;
    }

    if (it != auxContainer.end()) {
        auxContainer.insert(it, number);
    } else {
        auxContainer.push_back(number);
    }

    insertNumberInPos(pos, 0, container, DELETE);
    std::cout << "1:\n";
    printContainer(getContainer(ONE));
    std::cout << "2:\n";
    printContainer(getContainer(TWO));

}

std::vector<int>::iterator MergeInsortMakerVec::binarySearch(int value, std::vector<int>::iterator start, std::vector<int>::iterator end, int container) {
    int comparativeValue;
    std::vector<int>::iterator comparativePos;
    size_t var;
    size_t threshold;

    comparativePos = start;
    var = std::distance(getBegin(container), start);
    std::cout << *comparativePos << std::endl;
    std::cout << var << std::endl;
    threshold = (size_t)std::distance(start, end) / 2;
    for (size_t i = 0; i < threshold; ++i) {
        ++comparativePos;
        ++var;
    }
    std::cout << var << std::endl;
    comparativeValue = getNumber(var, container);

        std::cout << "vueltas" << std::endl;
    if (start == end)
        return comparativePos;

    if (comparativeValue == value)
        return comparativePos;

    if (comparativeValue > value)
        return binarySearch(value, start, comparativePos, container);
    else
        return binarySearch(value, ++comparativePos, end, container);
}

int MergeInsortMakerVec::getNumber(size_t position, int container) {

    std::cout << getItPos(container) << std::endl;
    std::cout << "2Pos: " << position << std::endl;

    std::cout << "Values on rotation:" << *getCurrent(container) << std::endl;
    while (position != getItPos(container)) {
        std::cout << "Values on rotation2:" << *getCurrent(container) << std::endl;
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

void printContainer(const std::vector<int>& cont) {
    std::cout << "Container: ";
    for (size_t i = 0; i < cont.size(); ++i) {
        std::cout << cont[i] << " ";
    }
    std::cout << "\n";
}
