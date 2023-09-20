#include <iostream>
#include <vector>
#include <list>

#define INSERT 1
#define DELETE -1
#define NEXT 1
#define PREV -1

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

    typename container::iterator binarySearch(int value, typename container::iterator start, typename container::iterator end) {
	    int comparativeValue;
	    typename container::iterator comparativePos;

	    comparativePos = start;
	    comparativeValue = getNumber(comparativePos, floor(end - start) / 2);

	    if (start == end) {
	        return comparativePos;
	    }

	    if (comparativeValue == value) {
	        return comparativePos;
	    }

	    if (bigger(comparativePos, start, true)) { 
	        return binarySearch(value, start, comparativePos);
	    } else {
	        return binarySearch(value, ++comparativePos, end);
	    }
	}


    int getNumber(size_t position) {
        int direction = position - _itPos;

        while (position != _itPos)
            next(direction < 0 ? PREV : NEXT);

        return *_current;
    }

    void insertNumberInPos(bool flag, int num = INSERT) { // Cambio aquí
        if (flag != DELETE)
            _current = _contenedor.insert(_current, num);
        else
            _current = _contenedor.erase(_current);
    }

    size_t size() const { // Cambio aquí
        return _contenedor.size();
    }

    bool bigger(typename container::iterator position1, typename container::iterator position2, bool equal) const {
        return (equal ? 
            *position1 >= *position2 : 
            *position1 > *position2);
    }

    void begin() {
        _current = _contenedor.begin();
        _itPos = 0;
    }

    void end() {
        _current = _contenedor.end();
        _itPos = size();
    }

    void next(bool flag = NEXT) {
        _current += flag;
        _itPos += flag;

        if (_itPos < 0)
            begin();
        if (_itPos >= size())
            end();
    }


    bool isEnd() const {
        return _current == _contenedor.end();
    }

    void insert(bool flag, int num = INSERT) {
        if (flag != DELETE)
            _current = _contenedor.insert(_current, num);
        else
            _current = _contenedor.erase(_current);
    }

    int& operator*() {
        return *_current;
    }

    int& operator[](size_t index) {
		int direction = index - _itPos;

		while (index != _itPos)
			next(direction < 0 ? PREV : NEXT);

		return *_current;
    }

    std::ostream& print(std::ostream& os) const {
        os << "MergeInsortMaker Content: ";
        for (begin(); isEnd(); next()) {
            os << *_current << " ";
        }
        return os;
    }
};

template <typename container>
std::ostream& operator<<(std::ostream& os, const MergeInsortMaker<container>& maker) {
    return maker.print(os);
}


