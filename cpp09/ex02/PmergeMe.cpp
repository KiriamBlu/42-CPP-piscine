#include "PmergeMe.hpp"

//------------------------------------------------------------VECTOR---------------------------------------------------------------//


void printContainerLONGVEC(const std::vector<long int>& cont);

MergeInsortMakerVec::MergeInsortMakerVec(std::vector<int> contenedor) : _contenedor(contenedor) {
    begin(ONE);
    begin(TWO);
}

void MergeInsortMakerVec::mergeInShort() {
    std::vector<long int> vec;
    size_t length = size(ONE);

    //std::cout << "MERGE\n";
    merge(vec, (length % 2) == 0 ? length : length - 1, ONE);
    std::cout << "1 ";
    printContainerVEC(getContainer(ONE));
    std::cout << "S ";
    printContainerVEC(getContainer(TWO));
    std::cout << "VECTOR EXTRA:\n";
    printContainerLONGVEC(vec);

    getContainer(TWO).insert(getBegin(TWO),vec[0]);
    getContainer(ONE).erase(std::find(getBegin(ONE), getEnd(ONE), vec[0]));

    vec.insert(vec.begin(), 0xFFFFFFFF);

    std::cout << "PASS\n";
    std::cout << "1 ";
    printContainerVEC(getContainer(ONE));
    std::cout << "S ";
    printContainerVEC(getContainer(TWO));
    std::cout << "VECTOR EXTRA:\n"; 
    printContainerLONGVEC(vec);

    // SWAP GROUPS OVER CONTAINER 1 IN ORDER 2^x - prev.x;

    std::cout << "INSERT\n";
    insert(ONE, vec);
    std::cout << "1 ";
    printContainerVEC(getContainer(ONE));
    std::cout << "S ";
    printContainerVEC(getContainer(TWO));
    std::cout << "VECTOR EXTRA:\n";
    printContainerLONGVEC(vec);

    //_contenedor = _contenedor2;
    //_contenedor2.clear();

    
}

void MergeInsortMakerVec::merge(std::vector<long int> &vec, size_t threshold, int container, size_t lap) {
    std::vector<int>& auxContainer = getContainer(OTHER(container));

    if (lap >= threshold)
        return;

    int package[2] = {getNumber(lap + 1, container), getNumber(lap, container)};
    merge(vec, threshold, container, lap + 2);
    int pos = (package[0] > package[1]) ? lap + 1 : lap;
    int number = (package[0] < package[1]) ? package[1] : package[0];
    package[0] = (package[0] < package[1]) ? package[0] : package[1];
    package[1] =  number; 

    if (auxContainer.empty()) {
        auxContainer.push_back(number);
        vec.push_back(package[0]);
        insertNumberInPos(pos, 0, container, DELETE);
        return ;
    }

    std::vector<int>::iterator it = auxContainer.begin();
    std::vector<long int>::iterator it2 = vec.begin();
    while (*it < number) {
        ++it;
        ++it2;
        if(it == auxContainer.end())
            break;
    }

    if (it != auxContainer.end()) {
        auxContainer.insert(it, number);
        vec.insert(it2, package[0]);
    } else {
        auxContainer.push_back(number);
        vec.push_back(package[0]);
    }

    insertNumberInPos(pos, 0, container, DELETE);
    return ;
}

// void MergeInsortMakerVec::groupSwapper(int container){
//     std::vector<int>& auxContainer = getContainer(container);
//     size_t swapper[2] = {0, 2};

//     for (size_t i = 0; i < auxContainer.size(), i ){
//         for (size_t swapper, )
//     }
// }

void MergeInsortMakerVec::insert(int container, std::vector<long int> &vec){
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


//------------------------------------------------------------LIST-----------------------------------------------------------------//

MergeInsortMakerList::MergeInsortMakerList(std::list<int> contenedor) : _contenedor(contenedor) {
    begin(ONE);
    begin(TWO);
}

void MergeInsortMakerList::mergeInShort() {
    size_t length = size(ONE);

    merge((length % 2) == 0 ? length : length - 1, ONE);

    insert(ONE);

    _contenedor = _contenedor2;
    _contenedor2.clear();

    std::cout << "1:\n";
    printContainerLIST(getContainer(ONE));
    std::cout << "2:\n";
    printContainerLIST(getContainer(TWO));
}

void MergeInsortMakerList::insert(int container) {
    std::list<int>& auxContainer = getContainer(container);
    std::list<int>& auxContainer2 = getContainer(OTHER(container));
    std::list<int>::iterator aux;
    int value;

    while (!auxContainer.empty()) {
        value = getNumber(0, container);
        insertNumberInPos(0, 0, container, DELETE);
        aux = binarySearch(value, getBegin(OTHER(container)), getEnd(OTHER(container)));
        auxContainer2.insert(aux, value);
    }
}

void MergeInsortMakerList::merge(size_t threshold, int container, size_t lap) {
    std::list<int>& auxContainer = getContainer(OTHER(container));

    if (lap >= threshold)
        return;

    int package[2] = {getNumber(lap + 1, container), getNumber(lap, container)};
    merge(threshold, container, lap + 2);
    int pos = (package[0] < package[1]) ? lap + 1 : lap;
    int number = (package[0] > package[1]) ? package[1] : package[0];
    package[0] = (package[0] > package[1]) ? package[0] : package[1];
    package[1] = number;

    if (auxContainer.empty()) {
        auxContainer.push_back(package[1]);
        auxContainer.push_back(package[0]);
        insertNumberInPos(lap, 0, container, DELETE);
        insertNumberInPos(lap, 0, container, DELETE);
        return;
    }

    std::list<int>::iterator it = auxContainer.begin();
    while (*it < number) {
        ++it;
        if (it == auxContainer.end())
            break;
    }

    auxContainer.insert(it, number);
    insertNumberInPos(pos, 0, container, DELETE);
}

std::list<int>::iterator MergeInsortMakerList::binarySearch(int value, std::list<int>::iterator start, std::list<int>::iterator end) {
    while (start != end) {

        if (*start == value) {
            return start;
        }

        if (*start > value) {
            end = start;
        } else {
            ++start;
        }
    }
    return start;
}

int MergeInsortMakerList::getNumber(size_t position, int container) {

    while (position != getItPos(container)) {
        next((position < getItPos(container)) ? PREV : NEXT, container);
    }
    return *getCurrent(container);
}

void MergeInsortMakerList::insertNumberInPos(size_t pos, int num, int container, int flag) {
    int direction = static_cast<int>(pos) - static_cast<int>(getItPos(container));

    while (pos != getItPos(container)) {
        next((direction < 0) ? PREV : NEXT, container);
    }
    insert(num, container, flag);
}

void MergeInsortMakerList::insert(int num, int container, int flag) {
    std::list<int>& auxContainer = getContainer(container);
    std::list<int>::iterator& auxIterator = (container == ONE) ? _current1 : _current2;

    if (flag != DELETE) {
        if (auxIterator == getBegin(container)) {
            auxContainer.insert(auxIterator, num);
        } else {
            auxIterator = auxContainer.insert(auxIterator, num);
        }
    } else {
        std::list<int>::iterator temp = auxIterator;
        if (auxIterator != getEnd(container)) {
            auxIterator = auxContainer.erase(temp);
        } else {
            auxContainer.pop_back();
            auxIterator = getEnd(container);
        }
        getCurrent(container) = auxIterator;
    }
}

void MergeInsortMakerList::begin(int container) {
    getCurrent(container) = (container == ONE) ? _contenedor.begin() : _contenedor2.begin();
    getItPos(container) = 0;
}

void MergeInsortMakerList::next(int direction, int container) {
    std::list<int>::iterator& auxIterator = (container == ONE) ? _current1 : _current2;
    size_t& auxNumPos = (container == ONE) ? _itPos1 : _itPos2;

    if (direction == NEXT) {
        ++auxIterator;
        ++auxNumPos;
    } else if (direction == PREV) {
        --auxIterator;
        --auxNumPos;
    }
}

std::list<int>& MergeInsortMakerList::getContainer(int container) {
    return (container == ONE) ? _contenedor : _contenedor2;
}

size_t MergeInsortMakerList::size(int container) {
    return (container == ONE) ? _contenedor.size() : _contenedor2.size();
}

std::list<int>::iterator& MergeInsortMakerList::getCurrent(int container) {
    return (container == ONE) ? _current1 : _current2;
}

size_t& MergeInsortMakerList::getItPos(int container) {
    return (container == ONE) ? _itPos1 : _itPos2;
}

std::list<int>::iterator MergeInsortMakerList::getBegin(int container) {
    return (container == ONE) ? _contenedor.begin() : _contenedor2.begin();
}

std::list<int>::iterator MergeInsortMakerList::getEnd(int container) {
    return (container == ONE) ? _contenedor.end() : _contenedor2.end();
}

void MergeInsortMakerList::printContent(std::ostream& os, int container) {
    os << "MergeInsortMakerList Content: ";
    std::list<int>& cont = getContainer(container);
    for (std::list<int>::const_iterator it = cont.begin(); it != cont.end(); ++it) {
        os << *it << " ";
    }
}
void printContainerLIST(const std::list<int>& cont) {
    std::cout << "Container: ";
    for (std::list<int>::const_iterator it = cont.begin(); it != cont.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
};


