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
    int (*getNumber)(typename container::iterator);
    void (*insertNumberInPos)(typename container::iterator, bool, int);
    size_t (*size)(const container&);

    MergeInsortMaker(container contenedor) : _contenedor(contenedor) {
    	begin();
    }

    MergeInsortMaker( container contenedor, 
                      int (*getNumberFunc)(typename container::iterator),
                      void (*insertNumberInPosFunc)(typename container::iterator, bool, int),
                      size_t (*sizeFunc)(const container&)): 
    				  _contenedor(contenedor), 
    				  getNumber(getNumberFunc),
        			  insertNumberInPos(insertNumberInPosFunc), 
        			  size(sizeFunc) 
        			  {
        			  	begin();
        			  }

   	MergeInsortMaker<container> copyFunctions( MergeInsortMaker<container> &second ){
   		this->getNumber = second.getNumber;
	    this->insertNumberInPos = second.insertNumberInPos;
	    this->size = second.size;

   	}

    bool bigger(typename container::iterator position1, typename container::iterator position2, bool equal) const {
        return (equal ? 
            getNumber(position1) >= getNumber(position2) : 
            getNumber(position1) > getNumber(position2));
    }

    void begin() {
        _current = _contenedor.begin();
        _itPos = 0;
    }

    void next(bool flag = NEXT) {
    	if(flag != PREV){
	        ++_current;
	        ++_itPos;
    	}
    	else{
    		--_current;
	        --_itPos;
    	}
    }

    bool isEnd() const {
        return _current == _contenedor.end();
    }

    void insert(bool flag, int num = INSERT) {
    	if(flag != DELETE)
        	insertNumberInPos(_contenedor.begin(), flag, num);
        else
        	insertNumberInPos(_contenedor.begin(), flag);
    }

    int& operator*() {
        return *_current;
    }

    int& operator[](size_t index) {
        if (index < size(_contenedor)) {
            typename container::iterator it = _contenedor.begin();
            std::advance(it, index);
            return *it;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

};

template <typename container>
typename container::iterator binarySearch(int value, typename container::iterator start, typename container::iterator end) {
    while (start != end) {
        typename container::iterator mid = start;
        std::advance(mid, std::distance(start, end) / 2);

        if (*mid == value)
            return mid;

        if (*mid > value)
            end = mid;
        else
            start = ++mid;
    }

    return end;
}
