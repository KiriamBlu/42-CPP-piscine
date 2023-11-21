#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <iostream>
#include <stack>


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
		~RPN ( void );


		void    setNewStr(std::string newStr);
		int    operate(void);
};

#endif
