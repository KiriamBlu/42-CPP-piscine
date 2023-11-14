
#include "Span.hpp"

/*------------------------------------------------------------------------*/

Span::Span( void ): _N( 0 ) {
}

Span::Span( unsigned int N ): _N( N ) {  
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

  _N = tmp.getN();
  _filled = tmp.getFilled();

  _storage.clear();
  for ( unsigned int x = 0; x < tmp.getFilled(); x++ )
    _storage.push_back( tmp.getNumberIndex(x) );

  return (*this);
}


int  &Span::operator[]( unsigned int iter ){
  if(iter > _N)
    throw vectorIndexOutLimits();
  return _storage[iter];
}

/*------------------------------------------------------------------------*/

void Span::addNumber( int number ) {
  if( _filled == _N )
    throw noSpaceLeft();

  _storage.push_back(number);
  _filled++;
}

void     Span::addRange( int start, int end ){
  
  int length = ( end - start + 1 );

  if( length <= 0 )
    throw invalidRange();
  if( _filled + length > _N )
    throw noSpaceLeft();

  for( int x = start; x <= end ; x++ )
    _storage.push_back( x );
  _filled += length;
}

void Span::addArrVector( std::vector<int>& vector ) {

  unsigned int length = vector.size();

  if( vector.empty() )
    throw emptyVector();
  if( _filled + length > _N ) 
    throw noSpaceLeft();

  _storage.insert( _storage.begin(), vector.begin(), vector.end() );
  
  _filled += vector.size();
}

/*------------------------------------------------------------------------*/

int  Span::shortestSpan( void ){
  if(_filled <= 1)
    throw notEnoughNumbers();

  int maxElement = *std::max_element( _storage.begin(), _storage.end() );

  for( std::vector<int>::iterator it1 = _storage.begin(); it1 != _storage.end(); it1++ ){
    for( std::vector<int>::iterator it2 = std::next(it1); it2 != _storage.end(); it2++ ){
      int shotestDifference = abs( *it2 - *it1 );
      if ( maxElement > shotestDifference ){
        _numbers[0] = *it2;
        _numbers[1] = *it1;
        maxElement = shotestDifference;
      }  
    }    
  }
  return(maxElement);
}

int  Span::longestSpan( void ){
  if(_filled <= 1)
    throw notEnoughNumbers();

  int minElement = *std::min_element( _storage.begin(), _storage.end() );

  for( std::vector<int>::iterator it1 = _storage.begin(); it1 != _storage.end(); it1++ ){
    for( std::vector<int>::iterator it2 = std::next(it1); it2 != _storage.end(); it2++ ){
      int longestSpan = abs( *it2 - *it1 );
      if ( minElement < longestSpan ){
        _numbers[0] = *it2;
        _numbers[1] = *it1;
        minElement = longestSpan;
      }
    }    
  }
  
  return(minElement);
}

/*------------------------------------------------------------------------*/

unsigned int Span::getFilled(void) const{
  return _filled;
}

int     Span::getN(void) const{
  return _N;
}

int   Span::getNumberIndex( unsigned int index ) const{
  return _storage[index];
}

int       *Span::getNumbers(void){
  return _numbers;
}

void Span::printValues( void ) const {
  std::cout << "Values in Span container: ";

  if (_storage.empty())
      std::cout << "Empty";
  else 
      for ( unsigned int x = 0; x < _filled ; x++) 
          std::cout << _storage[x] << " ";
  
  std::cout << std::endl;
} 

/*------------------------------------------------------------------------*/



