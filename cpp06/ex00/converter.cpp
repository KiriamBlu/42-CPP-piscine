
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

std::ostream &Converter::print_Value(char type, const std::string& value, std::ostream& os) {
  os << value;
  try {
    setAnyValue(type);
    switch (type) {
      case 'C':
        return os << this->getValueChar() << std::endl;
      case 'I':
        return os << this->getValueInt() << std::endl;
      case 'F':
        return os << this->getValueFloat() << ((this->valueFloat - this->valueInt) != 0 ? "f" : ".0f") << std::endl;
      case 'D':
        return os << this->getValueDouble() << std::endl;
    }
  } catch (const char* err) {
    return os  << err << std::endl;
  }
  return os;
}

std::ostream &operator<<(std::ostream& os,Converter &tmp) {
  tmp.print_Value('C', "char: ", os);
  tmp.print_Value('I', "int: ", os);
  tmp.print_Value('F', "float: ", os);
  tmp.print_Value('D', "double: ", os);
  return os;
} 



void Converter::setAnyValue(char type) {

  if (!this->inputString.compare("+inf") && (type == 'F' || type == 'D')) {
    throw "inf";
  }else if (!this->inputString.compare("-inf") && (type == 'F' || type == 'D')) {
    throw "-inf";
  }else {
    try {
      switch (type) {
        case 'C':

          if (!isprint(std::stoi(this->inputString)))
            throw "Non displeyeable";
          this->valueChar = static_cast<char>(std::stoi(this->inputString));
          
          break;

        case 'I':

          this->valueInt = static_cast<int>(std::stoi(this->inputString));
          
          break;

        case 'F':

          if (!this->inputString.compare("nan"))
              throw "nanf";
          this->valueFloat = static_cast<float>(std::stof(this->inputString));
          
          break;

        case 'D':

          if (!this->inputString.compare("nan"))
            throw "nan";
          this->valueDouble = static_cast<double>(std::stod(this->inputString));
          
          break;
        default:
          return;
      }
    } catch (const char* err) {
        throw err;
    } catch (...) {
        throw "Impossible";
    }
  }
}

void Converter::fillValue(std::string str){
  this->inputString = str;
}

std::string Converter::getInputString() const {
  return this->inputString;
}

char Converter::getValueChar() const {
  return this->valueChar;
}

int Converter::getValueInt() const {
  return this->valueInt;
}

float Converter::getValueFloat() const {
  return this->valueFloat;
}

double Converter::getValueDouble() const {
  return this->valueDouble;
}
