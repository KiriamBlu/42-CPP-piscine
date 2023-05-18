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
  	void			print_Value(char type, const std::string& value, std::ostream& os);

  	void 			fillValue(std::string str);
  	void			setChar(std::string &str);
  	void			setInt(std::string &str);
  	void			setFloat(std::string &str);
  	void			setDouble(std::string &str);

  	std::string 	getInputString(void) const;
	char 			getValueChar() const;
	int 			getValueInt() const;
	float 			getValueFloat() const;
	double 			getValueDouble() const;

};
std::ostream& operator<<(std::ostream& os, Converter& converter);

#endif
