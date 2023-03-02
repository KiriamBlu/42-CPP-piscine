#ifndef REPLACER_HPP
#define REPLACER_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class	replacer {

	public:
		void replace_in_file( std::string file, std::string one, std::string two);
		replacer ( void );
		~replacer ( void );
};

#endif
