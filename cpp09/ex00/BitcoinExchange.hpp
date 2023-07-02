#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <string>
#include <iostream>
#include <multimap>

class	BitcoinExchange {

	private:
		std::multimap<, > storage;
	public:
		BitcoinExchange ( void );
		BitcoinExchange ( std::string str );
		BitcoinExchange~ ( void );

		void	loadCsv(std::string fileName);
};

#endif
