

#include "PmergeMe.hpp"

template <typename container>
std::ostream& operator<<(std::ostream& os, const MergeInsortMaker<container>& maker)  {
    os << "MergeInsortMaker Content: ";
    for (typename container::iterator it = maker._contenedor.begin(); it != maker._contenedor.end(); ++it) {
        os << *it << " ";
    }
    return os;
}
/*
template <typename container>
void merge_insert(const MergeInsortMaker<container>& cont1){
  container aux;
  MergeInsortMaker<container>& cont2(aux);


  


}*/

/**************************************========================**************************************/

