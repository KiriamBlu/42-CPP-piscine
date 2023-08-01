#include "RPN.hpp"

std::string  RPN::checkRPN(std::string str){
  size_t lenght = str.length();
  int j = 0;
  int i = 0;

  while( str[i] ){
    if(isdigit(str[i])){
      while(isdigit(str[i++]) && str[i]);
      j++;
    }
    else if(compareWithDict(str[i], " *+-/"))
      i++;
    else
      break;
  }
  if(i != (int)lenght)
    return "ERROR: Not allowed char [" + std::string(1, str[i]) + "] on pos " + std::string(1, i);
  if(j > 10)
    return "ERROR: Bad reverse polish notation";
  return (str);
}

RPN::RPN( std::string str ) {
  this->str = checkRPN(str);
}

RPN::~RPN( void ) {
  
}

void    RPN::setNewStr(std::string newStr){
   this->str = checkRPN(newStr);
}

int RPN::popAndRet(void){
  int var = this->storage.top();
  std::cout << var << std::endl;
  this->storage.pop();
  std::cout << this->storage.top() << std::endl;
  return var;
}

int RPN::operateTwoValues(int value1, int value2, int op){
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
  for (int i = 0 ; i < (int)dict.length() - 1;  i++)
    if (dict[i] == character)
      return 1;
  return 0;
}

void    RPN::operate(void){
  int    i = 0; 
  int    j;

  while(str[i] && this->str[0] != 'E'){
    try{
      while(!isdigit(str[i++]) && str[i])
        if(this->compareWithDict(str[i], "*+-/"))
          this->storage.push(operateTwoValues(this->popAndRet(), this->popAndRet(), str[i]));
    }
    catch(...){
      throw (std::runtime_error("Error: Not posible computing"));
    }
    
    j = i;

    while(isdigit(str[j++]) && str[j]);
    
    if(j != i)
      this->storage.push(atoi(str.substr(i, j).c_str()));
    i = j;
  } 
  if(this->str[0] == 'E')
    throw(std::runtime_error(this->str));
  std::cout << this->storage.size() << std::endl;
  if(this->storage.size() != 1)
    std::cout << "Error: Not posible computing" << std::endl;
  else
    std::cout << this->storage.top() << std::endl; 
}