#include "RPN.hpp"

inline static std::strings  checkRPN(std::string str){
  size_t lenght = str.length();

  while(isdigit(str[i]) || str[i] == ' ' || str[i] = '*' || str[i] = '/' || str[i] = '+'|| str[i] = '-')
      i++;
    if(i != lenght - 1)
      return "ERROR: Not allowed char [" + str[i] + "]";
    if(lenght > 10)
      return "ERROR: Bad reverse polish notation";
}

RPN::RPN( std::string str ): {
  this->str = checkRPN(str);
}

RPN::RPN~( void ) {
  
}

void    setNewStr(std::string newStr){
   this->str = checkRPN(newStr);
}

void    RPN::operate(void);