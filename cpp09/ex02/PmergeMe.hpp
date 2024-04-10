#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>

#define INSERT 1
#define DELETE -1
#define NEXT 1
#define PREV -1

#define ONE 0
#define TWO 1

#define OTHER(container) container == ONE ? TWO : ONE


void printContainerVEC(const std::vector<int>& cont);

class MergeInsortMakerVec {
private:
    std::vector<int> _contenedor;
    std::vector<int> _contenedor2;
    std::vector<int>::iterator _current1;
    std::vector<int>::iterator _current2;
    size_t _itPos1;
    size_t _itPos2;

public:
    MergeInsortMakerVec(std::vector<int> contenedor);

    void mergeInShort();
    void merge(size_t threshold, int container, size_t lap = 0);
    void fixSecuencies(int container);
    void getPairs(std::vector<long int> &vec ,int container);
    void insert(int container, std::vector<long int> &vec);
    std::vector<int>::iterator binarySearch(std::vector<long int> &vec, int value, std::vector<int>::iterator start, std::vector<int>::iterator end);
    int getNumber(size_t position, int container);
    void insertNumberInPos(size_t pos, int num, int container, int flag = INSERT);
    void insert(int num, int container, int flag = INSERT);
    void begin(int container);
    void next(int direction, int container);
    std::vector<int>& getContainer(int container) ;
    size_t size(int container) ;
    std::vector<int>::iterator& getCurrent(int container);
    size_t& getItPos(int container);
    std::vector<int>::iterator getBegin(int container);
    std::vector<int>::iterator getEnd(int container);
    void printContent(std::ostream& os, int container);
};


void printContainerLIST(const std::list<int>& cont);

class MergeInsortMakerList {
private:
    std::list<int> _contenedor;
    std::list<int> _contenedor2;
    std::list<int>::iterator _current1;
    std::list<int>::iterator _current2;
    size_t _itPos1;
    size_t _itPos2;

public:
    MergeInsortMakerList(std::list<int> contenedor);

    void mergeInShort();
    void merge(size_t threshold, int container, size_t lap = 0);
    void insert(int container);
    std::list<int>::iterator binarySearch(int value, std::list<int>::iterator start, std::list<int>::iterator end);
    int getNumber(size_t position, int container);
    void insertNumberInPos(size_t pos, int num, int container, int flag = INSERT);
    void insert(int num, int container, int flag = INSERT);
    void begin(int container);
    void next(int direction, int container);
    std::list<int>& getContainer(int container);
    size_t size(int container);
    std::list<int>::iterator& getCurrent(int container);
    size_t& getItPos(int container);
    std::list<int>::iterator getBegin(int container);
    std::list<int>::iterator getEnd(int container);
    void printContent(std::ostream& os, int container);
};

#endif
