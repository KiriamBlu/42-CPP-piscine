#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>

class	BitcoinExchange {

	private:
		std::multimap<time_t, float> storage;


			

	public:
		BitcoinExchange		( void );
		BitcoinExchange		( std::string fileName );
		~BitcoinExchange	( void );

		void	loadStorage(std::string fileName);
		size_t 	size(void);
		std::multimap<time_t, float>::iterator getIterator(void);
		std::string	convertTimeToDate(time_t time);
};
std::ostream& operator<<(std::ostream& out, BitcoinExchange& exchange);

#endif
