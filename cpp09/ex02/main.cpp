
#include "PmergeMe.hpp"

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

int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(25);

    MergeInsortMaker<std::vector<int> > maker(vec, getNumberVector, insertNumberInPosVector, sizeVector);


    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);
    lst.push_back(25);

    MergeInsortMaker<std::list<int> > maker2(lst, getNumberList, insertNumberInPosList, sizeList);


    return 0;
}



int getNumberVector(typename std::vector<int>::iterator it) {
    return *it;
}

void insertNumberInPosVector(typename std::vector<int>::iterator it, bool flag , int num = 0 ) {
    if (flag == INSERT)
        it = _contenedor.insert(it, num);
    else
        it = _contenedor.emplace(it, num);
}

size_t sizeVector(const std::vector<int>& v) {
    return v.size();
}

int getNumberList(typename std::list<int>::iterator it) {
    return *it;
}

void insertNumberInPosList(typename std::list<int>::iterator it, bool flag ,int num = 0) {
    if (flag == INSERT)
        it = _contenedor.insert(it, num);
    else
        it = _contenedor.emplace(it, num);
}

size_t sizeList(const std::list<int>& l) {
    return l.size();
}
