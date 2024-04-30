#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm> 
#include <ctime>

#define INSERT 1
#define DELETE -1
#define NEXT 1
#define PREV -1

#define DEBUG 0

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
    void groupSwapper(int container);
    void insertAlg(int container, std::vector<long int> &vec);
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
    void printAndTime(std::vector<long int> &vec);
};

//------------------------------------------------------------DEQUE-----------------------------------------------------------------//

class MergeInsortMakerDeque {
private:
    std::deque<int> _contenedor;
    std::deque<int> _contenedor2;
    std::deque<int>::iterator _current1;
    std::deque<int>::iterator _current2;
    size_t _itPos1;
    size_t _itPos2;

public:
    MergeInsortMakerDeque(std::deque<int> contenedor);

    void mergeInShort();
    void merge(size_t threshold, int container, size_t lap = 0);
    void fixSequences(int container);
    void getPairs(std::deque<long int> &deq ,int container);
    void groupSwapper(int container);
    void insertAlg(int container, std::deque<long int> &deq);
    std::deque<int>::iterator binarySearch(std::deque<long int> &deq, int value, std::deque<int>::iterator start, std::deque<int>::iterator end);
    int getNumber(size_t position, int container);
    void insertNumberInPos(size_t pos, int num, int container, int flag = INSERT);
    void insert(int num, int container, int flag = INSERT);
    void begin(int container);
    void next(int direction, int container);
    std::deque<int>& getContainer(int container);
    size_t size(int container);
    std::deque<int>::iterator& getCurrent(int container);
    size_t& getItPos(int container);
    std::deque<int>::iterator getBegin(int container);
    std::deque<int>::iterator getEnd(int container);
    void printContent(std::ostream& os, int container);
    void printAndTime(std::deque<long int> &deq);
};
void printContainerDEQUE(const std::deque<int>& cont);

#endif
