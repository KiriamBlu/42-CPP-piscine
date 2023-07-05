#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <string>
#include <iostream>
#include <multimap>
#include <fstream>

class	BitcoinExchange {

	private:
		std::multimap<, > storage;

	public:
		BitcoinExchange ( void );
		BitcoinExchange ( std::string str );
		BitcoinExchange~ ( void );

		void	loadStorage(std::string fileName);
};

#endif
