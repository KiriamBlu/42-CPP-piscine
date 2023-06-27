
#include "MutantStack.hpp"

MutantStack::MutantStack( void ) {}

MutantStack::MutantStack( const std::stack<T> &stack ): storage(stack){}

MutantStack::MutantStack( const MutantStack & var ) {
MutantStack::iterator::*this = var;
  return ;
  
}

MutantStack::~MutantStack( void ) {
  return ;

}

T     &MutantStack::operator[](std::size_t index){
  return this->getElement(index);
} 

MutantStack & MutantStack::operator=(const MutantStack &tmp) {
  if(*this == tmp)
    return (*this);
  (void) tmp;
  return (*this);
}

T& getElement(std::size_t index) {
  std::stack<T> tempStack = this->storage;

  for (std::size_t i = 0; i < index; i++) {
      tempStack.pop();
  }

  return tempStack.top();
}

T                 &MonsterStack::top( void ){
  return  this->storage.top();
}

std::size_t       MonsterStack::size( void ){
  return  this->storage.size();
}

void              MonsterStack::push( const T value ){
  this->storage.push(value);
}

void              MonsterStack::pop( void ){
  this->storage.pop();
}

iterator          &MonsterStack::begin( void ){
  MonsterStack::iterator<T> it(this, 0);
  return it;
}

iterator          &MonsterStack::end( void ){
  MonsterStack::iterator<T> it(this, this->storage.size());
  return it;
}

/////////////////////////////////////////////////////////////////////////////////////////

MutantStack::iterator::iterator(MutantStack<T>& s, std::size_t i): stack(s), index(i) {}


T       &MutantStack::iterator::operator*(void) const{
  return this->stack[this->index]
}

MutantStack::iterator &MutantStack::iterator::operator++(void) const {
    this->index++;
    return *this;
}

MutantStack::iterator &MutantStack::iterator::operator--(void) const {
    this->index--;
    return *this;
}

bool      MutantStack::iterator::operator!=(const iterator& other) const{
  if(this->storage[this->index] != other->getElement(this->index))
    return (true);
  return(false);
}

bool      MutantStack::iterator::operator==(const iterator& other) const{
  if(this->storage[this->index] == other->getElement(this->index))
    return (true);
  return(false);
}
