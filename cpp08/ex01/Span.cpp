
#include "Span.hpp"

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
  if( iter > this->N )
    throw vectorIndexOutLimits().throwException( "index out of range" );
  return this->storage[iter];
}

void Span::addNumber( int number ) {
  if( this->filled == this->N )
    throw vectorIndexOutLimits().throwException( "No space left" );

  storage.push_back(number);
  this->filled++;
}

void     Span::addRange( int start, int end ){
  
  int length = ( end - start + 1 );

  if( length <= 0 )
    throw vectorIndexOutLimits().throwException( "Invalid range" );
  if( this->filled + length > this->N )
    throw vectorIndexOutLimits().throwException( "No space left" );

  for( int x = start; x <= end ; x++ )
    this->storage.push_back( x );
  this->filled += length;
}

void Span::addArrVector( std::vector<int>& vector ) {
  unsigned int length = vector.size();

  if( this->filled + length > this->N ) {
    throw vectorIndexOutLimits().throwException( "No space left" );
  }

  for( unsigned int x = 0; x < length; x++ ) {
    storage.push_back( vector[x] );
  }

  this->filled += length;
}

int  Span::shortestSpan(void){
  if(this->filled <= 1)
    throw vectorIndexOutLimits().throwException( "Not enough numbers for span" );

  std::sort( this->storage.begin(), this->storage.end() );
  int maxElement = *std::max_element( this->storage.begin(), this->storage.end() );

  for( std::vector<int>::iterator it1 = this->storage.begin(); it1 != this->storage.end(); it1++ ){
    for( std::vector<int>::iterator it2 = std::next(it1); it2 != this->storage.end(); it2++ ){
      int difference = ( *it2 - *it1 );
      if ( maxElement > difference )
        maxElement = difference;
    }    
  }
  return(maxElement);
}

int Span::longestSpan() {
  if ( filled <= 1 ) {
    throw vectorIndexOutLimits().throwException( "Not enough numbers for span" );
  }

  std::sort( this->storage.begin(), this->storage.end() );

  int longestSpan = this->storage[this->filled - 1] - this->storage[0];

  return longestSpan;
}

