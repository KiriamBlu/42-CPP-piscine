#ifndef MERGEINSORTMAKER_HPP
#define MERGEINSORTMAKER_HPP

#include <string>
#include <iostream>
#include <vector>
#include <list>

#define IDLE -1

template <typename container>
class MergeInsortMaker {

private:
    container _contenedor;

    int (*getNumber)(size_t index);
    void (*insertNumberInPos)(size_t index, int number, bool flag);
    size_t (*size)(void);


public:

    MergeInsortMaker(container contenedor,
                     int (*getNumber)(size_t index),
                     void (*insertNumberInPos)(size_t index, int number),
                     size_t (*size)(void));

    bool bigger(size_t position1, size_t position2, bool equal);


    ~MergeInsortMaker(void);
    int& operator[](size_t index);
};

std::ostream &operator<<(std::ostream &os, const MergeInsortMaker &tmp);

#endif
