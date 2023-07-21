#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>

enum errorStatus{
	BAD_FORMAT_DATE = -1,
	BAD_NUMBER = -2
};

class	BitcoinExchange {

	private:
		std::multimap<time_t, float> storage;

		int 	StringEraseAp(int start, int iteratorDir, std::string &aux, int character);
		int		checkStrs(std::string *strings);
		bool	 dateFormat(const std::string& input);


	public:
		BitcoinExchange		( void );
		BitcoinExchange		( std::string fileName );
		~BitcoinExchange	( void );

		void	loadStorage(std::string fileName, std::multimap<time_t, float> &storage, int limiter);
		size_t 	size(void);
		std::multimap<time_t, float>::iterator getIterator(void);
		std::string	convertTimeToDate(time_t time);
};
std::ostream& operator<<(std::ostream& out, BitcoinExchange& exchange);

#endif
