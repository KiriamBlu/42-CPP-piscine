#include <iostream>
#include <vector>
#include <algorithm>

#define INSERT 1
#define DELETE -1
#define NEXT 1
#define PREV -1

#define ONE 0
#define TWO 1

#define OTHER(container) container == ONE ? TWO : ONE

void printContainer(const std::vector<int>& cont);

class MergeInsortMakerVec {
private:
    std::vector<int> _contenedor;
    std::vector<int> _contenedor2;
    std::vector<int>::iterator _current1;
    std::vector<int>::iterator _current2;
    size_t _itPos1;
    size_t _itPos2;

public:
    MergeInsortMakerVec(std::vector<int> contenedor) : _contenedor(contenedor) {
        begin(ONE);
        begin(TWO);
    }

    void mergeInShort() {
        size_t length = size(ONE) + size(TWO);

        merge((length % 2 == 0) ? length : length - 1, ONE);
        //insert();
    }

    void merge(size_t threshold, int container, size_t lap = 0,) {
        std::vector<int>* auxContainer = getContainer(container);

        if (lap >= threshold)
            return;

        merge(threshold, container, lap + 2);

        int package[2] = {getNumber(lap + 1, container), getNumber(lap, container)};
        int pos = (package[0] < package[1]) ? lap : lap + 1;
        int number = getNumber(pos, container);

        if (auxContainer->empty()) {
            auxContainer->push_back(number);
            auxContainer->push_back(number);
            insertNumberInPos(pos, 0, OTHER(container), DELETE);
            insertNumberInPos(pos, 1, OTHER(container), DELETE);
            return;
        }

        std::vector<int>::iterator it = auxContainer->begin();
        while (it != auxContainer->end() && *it < number) {
            ++it;
        }

        if (it != auxContainer->end()) {
            auxContainer->insert(it, number);
        } else {
            auxContainer->push_back(number);
        }

        insertNumberInPos(pos, 0, OTHER(container), DELETE);

        printContainer(*auxContainer);
    }

    std::vector<int>::iterator binarySearch(int value, int index, std::vector<int>::iterator start, std::vector<int>::iterator end, int container) {
        int comparativeValue;
        std::vector<int>::iterator comparativePos;

        comparativePos = start;
        for (size_t i = 0; i < distance / 2; ++i) {
            ++comparativePos;
        }
        comparativeValue = getNumber(comparativePos, container);

        if (start == end)
            return comparativePos;

        if (comparativeValue == value)
            return comparativePos;

        if (comparativeValue > value)
            return binarySearch(value, index, start, comparativePos, container);
        else
            return binarySearch(value, index, ++comparativePos, end, container);
    }

    int getNumber(size_t position, int container) {
        while (position != getItPos(container)) {
            next((position < getItPos(container)) ? PREV : NEXT, container);
        }
        return *_current(container);
    }

    void insertNumberInPos(size_t pos, int num, int container, int flag = INSERT) {
        int direction = static_cast<int>(pos) - static_cast<int>(getItPos(container));

        while (pos != getItPos(container))
            next((direction < 0) ? PREV : NEXT, container);

        insert(num, container, flag);
    }

    void insert(int num, int container, int flag = INSERT) {
        std::vector<int>::iterator* auxIterator;
        size_t* auxNumPos;

        if (container == ONE) {
            auxIterator = &_current1;
            auxNumPos = &_itPos1;
        } else {
            auxIterator = &_current2;
            auxNumPos = &_itPos2;
        }

        if (flag != DELETE) {
            **auxIterator = getContainer(container).insert(*(*auxIterator), num);
            ++(*auxNumPos);
        } else {
            if (*auxIterator != getBegin(container)) {
                std::vector<int>::iterator temp = *auxIterator;
                next(NEXT, container);
                getContainer(container).erase(temp);
                --(*auxNumPos);
            }
        }
    }

    void begin(int container) {
        _current(container) = (container == ONE) ? _contenedor.begin() : _contenedor2.begin();
        _itPos(container) = 0;
    }

    void next(int direction, int container) {
        std::vector<int>::iterator* auxIterator;
        size_t* auxNumPos;

        if (container == ONE) {
            auxIterator = &_current1;
            auxNumPos = &_itPos1;
        } else {
            auxIterator = &_current2;
            auxNumPos = &_itPos2;
        }

        if (direction == NEXT && *auxIterator != getEnd(container)) {
            ++(*auxIterator);
            ++(*auxNumPos);
        } else if (direction == PREV && *auxIterator != getBegin(container)) {
            --(*auxIterator);
            --(*auxNumPos);
        }
    }

    std::vector<int>& getContainer(int container) const {
        return (container == ONE) ? _contenedor : _contenedor2;
    }

    size_t size(int container) const {
        return (container == ONE) ? _contenedor.size() : _contenedor2.size();
    }

    std::vector<int>::iterator& getCurrent(int container) {
        return (container == ONE) ? _current1 : _current2;
    }

    size_t& getItPos(int container) {
        return (container == ONE) ? _itPos1 : _itPos2;
    }

    std::vector<int>::iterator getBegin(int container) {
        return (container == ONE) ? _contenedor.begin() : _contenedor2.begin();
    }

    std::vector<int>::iterator getEnd(int container) {
        return (container == ONE) ? _contenedor.end() : _contenedor2.end();
    }

    void printContent(std::ostream& os, int container) const {
        os << "MergeInsortMakerVec Content: ";
        for (std::vector<int>::const_iterator it = getContainer(container).begin(); it != getContainer(container).end(); ++it) {
            os << *it << " ";
        }
    }
};

std::ostream& operator<<(std::ostream& os, const MergeInsortMakerVec& maker) {
    maker.printContent(os, ONE);
       os << "\n";
    maker.printContent(os, TWO);
    return os;
}

void printContainer(const std::vector<int>& cont) {
    std::cout << "Container: ";
    for (const std::vector<int>::iterator element = cont.begin(); element < cont.end(); element++) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}
