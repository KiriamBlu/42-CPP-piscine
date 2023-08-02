
#include "converter.hpp"

Converter::Converter() {
  this->inputString = "";
  this->valueChar = '\0';
  this->valueInt = 0;
  this->valueFloat = 0.0f;
  this->valueDouble = 0.0;
}

Converter::~Converter( void ) {
  return ;
}

void Converter::print_Value(char type, const std::string& value, std::ostream& os) {
  os << value;
  try {
    switch (type) {
      case 'C':
        setChar(inputString);
        os << getValueChar() << std::endl;
        break; 
      case 'I':
        setInt(inputString);
        os << getValueInt() << std::endl;
        break;
      case 'F':
        setFloat(inputString);
        os << getValueFloat() << ((valueFloat - valueInt) != 0 ? "f" : ".0f") << std::endl;
        break;
      case 'D':
        setDouble(inputString);
        os << getValueDouble() << std::endl;
    }
  } 
  catch (const char* err){
   os  << err << std::endl;
  }
}

std::ostream &operator<<(std::ostream& os,Converter &tmp) {
  tmp.print_Value('C', "char: ", os);
  tmp.print_Value('I', "int: ", os);
  tmp.print_Value('F', "float: ", os);
  tmp.print_Value('D', "double: ", os);
  return os;
} 

void Converter::setChar(std::string &str){
  try {
    float intValue = std::stoi(str);
    if (!isprint(intValue))
      throw "Non displayable";
    valueChar = static_cast<char>(intValue);
  }
  catch (...) {
    throw "Impossible";
  }
}


void Converter::setInt(std::string &str){
  try{
    valueInt = static_cast<int>(std::stoi(str));
  } 
  catch (...) {
    throw "Impossible";
  }
}

void Converter::setFloat(std::string &str){

  if (!str.compare("+inf")) {
  
    throw "inf";
  
  } else if (!str.compare("-inf")) {

    throw "-inf";
  
  } else if (!str.compare("nan")){

    throw "nanf";
  
  } else{
    
    try{
      valueFloat = static_cast<float>(std::stof(str));
    }
    catch (...) {
      throw "Impossible";
    }
  }
}

void  Converter::setDouble(std::string &str){

  if (!str.compare("+inf")) {
  
    throw "inf";
  
  } else if (!str.compare("-inf")) {

    throw "-inf";
  
  } else if (!str.compare("nan")){

    throw "nan";
  
  } else{
    
    try{
      valueDouble = static_cast<double>(std::stod(str));
    }
    catch (...) {
      throw "Impossible";
    }
  }
}

void Converter::fillValue(std::string str){
  inputString = str;
}

std::string Converter::getInputString() const {
  return inputString;
}

char Converter::getValueChar() const {
  return valueChar;
}

int Converter::getValueInt() const {
  return valueInt;
}

float Converter::getValueFloat() const {
  return valueFloat;
}

double Converter::getValueDouble() const {
  return valueDouble;
}
