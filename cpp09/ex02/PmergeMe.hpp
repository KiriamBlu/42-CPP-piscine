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

    void copyFunctions(const MergeInsortMaker<container> &second) {
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

    void end() {
        _current = _contenedor.end();
        _itPos = size();
    }

    void next(bool flag = NEXT) {
        _current += flag;
        _itPos += flag;

        if(_itPos < 0)
            begin();
        if(_itPos >= size())
            end();
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
        size_t capacity = size();
        int direction = static_cast<int>(index) - static_cast<int>(_itPos);

        while(index != _itPos) {
            next(direction < 0 ? PREV : NEXT );
        }
        return *_current;
    }
	
	std::ostream& print(std::ostream& os) const {
        os << "MergeInsortMaker Content: ";
        for (typename container::iterator it = _contenedor.begin(); it != _contenedor.end(); ++it) {
            os << *it << " ";
        }
        return os;
    }
};


std::ostream& operator<<(std::ostream& os, const MergeInsortMaker<container>& maker);

