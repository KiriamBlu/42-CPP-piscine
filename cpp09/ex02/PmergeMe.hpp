#include <iostream>
#include <iterator>

#define INSERT 1
#define DELETE -1
#define NEXT 1
#define PREV -1

template <typename container>
void printContainer(const container& cont);

template <typename container>
class MergeInsortMaker {
private:
    container _contenedor;
    typename container::iterator _current;
    size_t _itPos;

public:
    MergeInsortMaker(container contenedor) : _contenedor(contenedor) {
        begin();
    }

    void mergeInShort() {
        container contenedor;
        size_t length = size();

        merge(contenedor, (length % 2 == 0) ? length : length - 1);
        

        printContainer(contenedor);

        _contenedor.clear();
        //_contenedor = contenedor;
    }

    void merge(container &contenedor, size_t threshold, size_t lap = 0) {
        if (lap >= threshold)
            return;

        merge(contenedor, threshold, lap + 2);
        int package[2] = {getNumber(lap + 1), getNumber(lap)};
        int pos = (package[0] < package[1]) ? lap : lap + 1;
        int number = getNumber(pos);

        if (contenedor.empty()) {
            contenedor.push_back(number);
            insertNumberInPos(pos, 0, DELETE);
            return;
        }

        typename container::iterator it = std::lower_bound(contenedor.begin(), contenedor.end(), number);

        if (it != contenedor.end()) {
            contenedor.insert(it, number);
        } else {
            contenedor.push_back(number);
        }

        insertNumberInPos(pos, 0, DELETE);
    }

    typename container::iterator binarySearch(int value, typename container::iterator start, typename container::iterator end) {
        int comparativeValue;
        typename container::iterator comparativePos;

        comparativePos = start;
        std::advance(comparativePos, std::distance(start, end) / 2);
        comparativeValue = getNumber(comparativePos);

        if (start == end)
            return comparativePos;

        if (comparativeValue == value)
            return comparativePos;

        if (bigger(comparativePos, start, true))
            return binarySearch(value, start, comparativePos);
        else
            return binarySearch(value, ++comparativePos, end);
    }

    int getNumber(size_t position) {
        int direction = position - _itPos;

        while (direction != 0) {
            next(direction < 0 ? PREV : NEXT);
            direction = position - _itPos;
        }

        return *_current;
    }

    void insertNumberInPos(size_t pos, int num, int flag = INSERT) {
        int direction = static_cast<int>(pos) - static_cast<int>(_itPos);

        while (pos != _itPos)
            next(direction < 0 ? PREV : NEXT);

        insert(num, flag);
    }

    void insert(int num, int flag = INSERT) {
        if (flag != DELETE) {
            _contenedor.insert(_current, num);
            ++_current;
            ++_itPos;
        } else {
            if (_current != _contenedor.begin()) {
                typename container::iterator temp = _current;
                next(NEXT);
                _contenedor.erase(temp);
                --_itPos;
            }
        }
    }

    void begin() {
        _current = _contenedor.begin();
        _itPos = 0;
    }

    void next(int direction) {
        if (direction == NEXT && _current != _contenedor.end()) {
            ++_current;
            ++_itPos;
        } else if (direction == PREV && _current != _contenedor.begin()) {
            --_current;
            --_itPos;
        }
    }

    const container& getContainer() const {
        return _contenedor;
    }

    void printContent(std::ostream& os) const {
        os << "MergeInsortMaker Content: ";
        for (typename container::const_iterator it = _contenedor.begin(); it != _contenedor.end(); ++it) {
            os << *it << " ";
        }
    }

    size_t size() const {
        return _contenedor.size();
    }
};

template <typename container>
std::ostream& operator<<(std::ostream& os, const MergeInsortMaker<container>& maker) {
    maker.printContent(os);
    return os;
}

template <typename container>
void printContainer(const container& cont) {
    std::cout << "container Content: ";
    typename container::const_iterator it = cont.begin();
    typename container::const_iterator end = cont.end();

    for (; it != end; ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}
