#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <iostream>
#include <stack>
#include <cstdlib>
//#define DEBUG 1

class	RPN {

	private:
		std::stack<int> storage;
		std::string str;

		bool 			compareWithDict(int character, std::string dict);
		int 			operateTwoValues(int value2, int value1, int op);
		int 			popAndRet(void);
		std::string		checkRPN(std::string str);

	public:

		RPN ( std::string str );
		RPN(const RPN& other);
    	RPN& operator=(const RPN& other);
		~RPN ( void );

		int    operate(void);
};

#endif
