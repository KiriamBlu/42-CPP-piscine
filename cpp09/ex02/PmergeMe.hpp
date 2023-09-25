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

    void mergeInShort(void){
    	container _contenedor;

    	merge(contenedor, floor(size() / 2));
    }

    void merge(container &contenedor, size_t threshold,size_t lap = 0){
    	size_t currentSize = size();

    	if(currentSize < threshold)
    		merge(contenedor, threshold, ++lap);

    	if(getNumber(lap + 1) > getNumber(lap + 2)){
    		int biggest = package[0];
    		int pos = lap + 1;
    	} else{
    		int biggest = package[1];
    		int pos = lap + 2;
    	}

    	int i = 0;
    	container::iterator end = contenedor.end();
    	for(container::iterator it = begin.begin(); *it > biggest && it != end ; i++);

    	_contenedor.insert(biggest, i);
    	insertNumberInPos(pos, DELETE);
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

        while (position != _itPos)
            next(direction < 0 ? PREV : NEXT);

        return *_current;
    }

    void insertNumberInPos(size_t num, bool flag = INSERT) { // Cambio aquí
        if (flag != DELETE)
            _current = _contenedor.insert(_current, num);
        else
            _current = _contenedor.erase(_current);
    }

    size_t size() const {
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

    void next(int flag = NEXT) {
        std::advance(_current, flag);
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

    std::ostream& print(std::ostream& os) {
        os << "MergeInsortMaker Content: ";
        for (begin(); !isEnd(); next()) {
            os << *_current << " ";
        }
        return os;
    }
};

template <typename container>
std::ostream& operator<<(std::ostream& os, MergeInsortMaker<container>& maker) {
    return maker.print(os);
}


