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
    	container contenedor;
    	size_t lenght;

    	lenght =  size();
    	merge(contenedor, lenght % 2 == 0 ? lenght : lenght - 1 );
    	//merge(contenedor);
    	printCont(contenedor);
    	//insert(contenedor);
    }

     void merge(container &contenedor, size_t threshold, size_t lap = 0) {
        if (lap >= threshold - 1)
            return; // Condición de parada

        // Llamada recursiva
        merge(contenedor, threshold, lap + 2);
        int package[2] = {getNumber(lap), getNumber(lap + 1)};
        int pos = (package[0] > package[1]) ? lap : lap + 1;
        int number = getNumber(pos);

        // Verificar si el contenedor está vacío
        if (contenedor.empty()) {
            contenedor.push_back(number);
            insertNumberInPos(pos, 0, DELETE);
            return;
        }

        typename container::iterator it = contenedor.begin();
        typename container::iterator end = contenedor.end();

        while (it != end && *it < number)
            it++;

        if (it != end) {
            contenedor.insert(it, number);
        } else {
            contenedor.push_back(number);
        }

        insertNumberInPos(pos, 0, DELETE);
    }
    
    /*void merge(container &contenedor){
    	size_t i[2] = {0, 1};
    	size_t threshold = (size_t)(size() / 2);
    	size_t pos;

    	for(size_t x = 0; x < threshold; x++){
    		if(getNumber(i[0]) > getNumber(i[1]))
    			pos = i[0];
    		else
    			pos = i[1];

	    	int number = getNumber(pos);
    		
    		if(x == 0)
	    		contenedor.push_back(number);
	    	else{
	    		typename container::iterator it = contenedor.begin();
    			typename container::iterator end = contenedor.end();
				while(*it < number && it != end)
					it++;

		    	contenedor.insert(--it, number);
				std::cout << x << std::endl; 
				if(x == 100)
					std::cout << getNumber(201) << std::endl;  		
		    	insertNumberInPos(pos, 0, DELETE);
	    	}
	    	i[0] += 2;
	    	i[1] += 2;
    	}
    }*/

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

        while (position != _itPos){
        	std::cout << position << std::endl;
            next(direction < 0 ? PREV : NEXT);
        }

        return *_current;
    }

    void insertNumberInPos(size_t pos, int num, int flag = INSERT) { // Cambio aquí
    	int direction = pos - _itPos;

        while (pos != _itPos)
            next(direction < 0 ? PREV : NEXT);
        if (flag != DELETE)
            _contenedor.insert(_current, num);
        else
            _contenedor.erase(_current);
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
    	std::cout <<   flag << std::endl;
        _itPos += flag;

        if (_itPos < 0)
            begin();
        else if (_itPos >= size())
            end();
        else
        	std::advance(_current, flag);
    }


    bool isEnd() const {
        return _current == _contenedor.end();
    }

    void insert( int num, int flag = INSERT) {
        if (flag != DELETE)
        	_contenedor.insert(_current, num);
        else
            _contenedor.erase(_current);
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

    void printCont(container contenedor) {
        for (typename container::iterator it = contenedor.begin(); it != contenedor.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
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


