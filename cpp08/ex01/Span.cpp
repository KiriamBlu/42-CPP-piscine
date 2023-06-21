
#include "Span.hpp"

/*------------------------------------------------------------------------*/

Span::Span( void ): N( 0 ) {
}

Span::Span( unsigned int N ): N( N ) {  
}

Span::Span( const Span & var ) {
  *this = var;
  return ;
}

Span::~Span( void ) {
}

/*------------------------------------------------------------------------*/

Span &Span::operator=(const Span &tmp) {
  if (this == &tmp)
    return (*this);

  this->N = tmp.N;
  this->filled = tmp.filled;

  this->storage.clear();
  for ( unsigned int x = 0; x < tmp.filled; x++ )
    this->storage.push_back( tmp.storage[x] );

  return (*this);
}


int  &Span::operator[]( unsigned int iter ){
  if( iter > this->N || !iter)
    throw vectorIndexOutLimits();
  return this->storage[iter];
}

/*------------------------------------------------------------------------*/

void Span::addNumber( int number ) {
  if( this->filled == this->N )
    throw noSpaceLeft();

  storage.push_back(number);
  this->filled++;
}

void     Span::addRange( int start, int end ){
  
  int length = ( end - start + 1 );

  if( length <= 0 )
    throw invalidRange();
  if( this->filled + length > this->N )
    throw noSpaceLeft();

  for( int x = start; x <= end ; x++ )
    this->storage.push_back( x );
  this->filled += length;
}

void Span::addArrVector( std::vector<int>& vector ) {

  unsigned int length = vector.size();

  if( vector.empty() )
    throw emptyVector();
  if( this->filled + length > this->N ) 
    throw noSpaceLeft();

  for( unsigned int x = 0; x < length; x++ )
    storage.push_back( vector[x] );
  
  this->filled += length;
}

/*------------------------------------------------------------------------*/

int  Span::shortestSpan( void ){
  int n1;
  int n2;
  if(this->filled <= 1)
    throw notEnoughNumbers();

  int maxElement = *std::max_element( this->storage.begin(), this->storage.end() );

  for( std::vector<int>::iterator it1 = this->storage.begin(); it1 != this->storage.end(); it1++ ){
    for( std::vector<int>::iterator it2 = std::next(it1); it2 != this->storage.end(); it2++ ){
      int shotestDifference = abs( *it2 - *it1 );
      if ( maxElement > shotestDifference ){
        n1 = *it2;
        n2 = *it1;
        maxElement = shotestDifference;
      }  
    }    
  }
  std::cout << "Number1:" << n1 << " Number2:" << n2 << std::endl;
  return(maxElement);
}

int  Span::longestSpan( void ){
  int n1;
  int n2;
  if(this->filled <= 1)
    throw notEnoughNumbers();

  int minElement = *std::min_element( this->storage.begin(), this->storage.end() );

  for( std::vector<int>::iterator it1 = this->storage.begin(); it1 != this->storage.end(); it1++ ){
    for( std::vector<int>::iterator it2 = std::next(it1); it2 != this->storage.end(); it2++ ){
      int longestSpan = abs( *it2 - *it1 );
      if ( minElement < longestSpan ){
        n1 = *it2;
        n2 = *it1;
        minElement = longestSpan;
      }
    }    
  }
  std::cout << "Number1:" << n1 << " Number2:" << n2 << std::endl;
  return(minElement);
}

/*------------------------------------------------------------------------*/

unsigned int Span::getFilled(void) const{
  return this->filled;
}

void Span::printValues( void ) const {
  std::cout << "Values in Span container: ";

  if (this->storage.empty())
      std::cout << "Empty";
  else 
      for ( unsigned int x = 0; x < this->filled ; x++) 
          std::cout << this->storage[x] << " ";
  
  std::cout << std::endl;
} 

/*------------------------------------------------------------------------*/



