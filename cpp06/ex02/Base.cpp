
#include "Base.hpp"

Base::~Base( void ) {
  return ;
}

A::~A( void ) {
  return ;
}

B::~B( void ) {
  return ;
}

C::~C( void ) {
  return ;
}

Base *generate(void){
  Base *aux;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 2);

  switch(distrib(gen)){
    case 0:
      aux = new A();
      break;
    case 1:
      aux = new B();
      break;
    case 2:
      aux = new C();
  }
  return aux;
}

void filter(Base *ptr){

  if(dynamic_cast<A*>(ptr))
    std::cout << "A" << std::endl;
  else if(dynamic_cast<B*>(ptr))
    std::cout << "B" << std::endl;
  else if(dynamic_cast<C*>(ptr))
    std::cout << "C" << std::endl;
  else
    std::cout << "Not valid input" << std::endl;

}