#include "RPN.hpp"

//#define DEBUG 1

std::string  RPN::checkRPN(std::string str){
  size_t lenght = str.length();
  int j = 0;
  int i = 0;

  while( str[i] ){
    if(isdigit(str[i])){
      if(isdigit(str[++i]))
         j++;
    }
    else if(compareWithDict(str[i], " *+-/") && str[i])
      i++;
    else
      break;
  }
  if(i != (int)lenght){
    std::cout << i << std::endl;
    return "ERROR: Not allowed char [" + std::string(1, str[i]) + "]";
  }
  if(j != 0)
     return "ERROR: Bad reverse polish notation";
  return (str);
}

RPN::RPN( std::string str ) {
  this->str = checkRPN(str);
}

RPN::~RPN( void ) {
  
}

int RPN::popAndRet(void){
  int var = this->storage.top();
  this->storage.pop();
  return var;
}

int RPN::operateTwoValues(int value2, int value1, int op){
  #ifdef DEBUG 
    std::cout << std::endl << "value1:(" << value1 << ") "  << "op: (" << char(op) << ") " << "value2:(" << value2 << ")" << std::endl << std::endl;
  #endif
  switch(op){
    case '*':
      return value1 * value2;
    case '-':
      return value1 - value2;
    case '+':
      return value1 + value2;
    case '/':
      return value1 / value2; 
  }
  return -1;
}

bool RPN::compareWithDict(int character, std::string dict)
{
  for (int i = 0 ; i < (int)dict.length();  i++)
    if (dict[i] == character)
      return 1;
  return 0;
}

int    RPN::operate(void){
  int    i = 0; 
  int    j;

  while(str[i] && this->str[0] != 'E'){
    try{
      while(!isdigit(str[i]) && str[i]){
        if(this->compareWithDict(str[i], "*+-/"))
        {
          if(this->storage.size() >= 2)
            this->storage.push(operateTwoValues(this->popAndRet(), this->popAndRet(), str[i]));
          else
            throw (std::runtime_error("Error: Not posible computing"));

          #ifdef DEBUG 
            std::cout << "RESULT AFTER: " << this->storage.top() << " lenght storage:" << this->storage.size() << std::endl;
          #endif
        }
        i++;
      }
    }
    catch(...){
      throw (std::runtime_error("Error: Not posible computing"));
    }
    
    j = i - 1;

    while(isdigit(str[++j]) && str[j]);
    
    if(j != i)
      this->storage.push(atoi(str.substr(i,  j - i).c_str()));
    i = j;
    #ifdef DEBUG 
      std::cout << "Lenght storage:" << this->storage.size() << std::endl;
    #endif
  } 
  if(this->str[0] == 'E')
    throw(std::runtime_error(this->str));
  if(this->storage.size() != 1)
    throw(std::runtime_error("Error: Not posible computing"));
  else
    return(this->storage.top());
  return 0;
}