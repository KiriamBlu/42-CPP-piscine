

#include "PmergeMe.hpp"


//void beginShort(void);
//size_t binarySearch(size_t start, size_t end, int value);

/**************************************======CONSTRUCTOR======***************************************/

MergeInsortMaker::MergeInsortMaker( container contenedor, 
                                    int ( *getNumber )( size_t index ),
                                    void ( *insertNumberInPos )( size_t index, int number, bool flag),
                                    size_t ( *size )( void )):
                                    _contenedor(contenedor),
                                    getNumber(getNumber),
                                    insertNumberInPos(insertNumberInPos),
                                    size(size)
                                    {

                                    }

/**************************************========METHODS========***************************************/

bool    MergeInsortMaker::bigger(size_t position1, size_t position2, bool equal){
  return(
        equal == 1 ?
        (getNumber(position1) >= getNumber(position2))
         : 
        (getNumber(position1) > getNumber(position2))
        );
}


size_t  binarySearch(int value, size_t start, size_t end, MergeInsortMaker contenedor){
  int comparativeValue;
  size_t size;

  comparativePos = floor((end / 2)) - 1;
  comparativeValue = contenedor.getNumber(comparativePos);

  if(mod(end - 1 - comparativePos) == 1 ){
    if(comparativeValue > value)
      return(comparativePos);
    else
      return(end);
  }

  if( comparativeValue > value ){
    return( binarySearch(value, start, comparativePos, contenedor) );
  } else{
    return( binarySearch(value, comparativePos, end, contenedor) );
  } 

}

/**************************************==LIST_IMPLEMENTATION==***************************************/

/**************************************=VECTOR_IMPLEMENTATION=***************************************/

/**************************************========================**************************************/

