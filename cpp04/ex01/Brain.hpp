
#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>

class	Brain {

	protected:
		std::string _ideas[100];
	public:

		Brain ( void );
		Brain ( std::string str );
		Brain ( const Brain & var );
		~Brain ( void );
		Brain &operator=(const Brain &tmp);
};

#endif
