#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>

class Converter {
private:

  	std::string 	inputString;
  	char 			valueChar;
  	int 			valueInt;
  	float 			valueFloat;
  	double 			valueDouble;

public:

  	Converter();
  	~Converter();

  	void 			setInputString(const std::string& input);
  	std::ostream 	&print_Value(char type, const std::string& value, std::ostream& os);

  	void 			setAnyValue(char type);
  	void 			fillValue(std::string str);

  	std::string 	getInputString(void) const;
	char 			getValueChar() const;
	int 			getValueInt() const;
	float 			getValueFloat() const;
	double 			getValueDouble() const;

};
std::ostream& operator<<(std::ostream& os, Converter& converter);

#endif
