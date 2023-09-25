
#include "PmergeMe.hpp"



int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(25);

    MergeInsortMaker<std::vector<int> > maker(vec);
    std::cout << "1 Before: " << maker << std::endl; 


    std::cout << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);
    lst.push_back(25);

    MergeInsortMaker<std::list<int> > maker2(lst);
    std::cout << "1 Before: " << maker2 << std::endl; 


    return 0;
}



