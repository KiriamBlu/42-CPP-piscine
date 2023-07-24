#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <ctime>

enum identifyer{
	LOCAL = 0,
	REMOTE = 1
};

enum errorStatus{
	BAD_FORMAT_DATE = -1,
	BAD_NUMBER = -2
};

class	BitcoinExchange {

	private:
		std::vector<std::pair<std::string, float> > storage;

		int 													StringEraseAp(int start, int iteratorDir, std::string &aux, int character);
		void													checkStrs(std::string date, float value);


	public:
		BitcoinExchange	( void );
		BitcoinExchange	( std::string fileName );
		~BitcoinExchange( void );

		size_t 													size(void);
		std::vector<std::pair<std::string, float> >::iterator 	getIterator(void);
		time_t													convertTimeToDate(std::string time);

		void													findAndCompare(std::vector<std::pair<std::string, float> > storage);
		void 													loadStorage(std::string fileName, std::vector<std::pair<std::string, float> >& storage, int limiter);


};
std::ostream& operator<<(std::ostream& out, BitcoinExchange& exchange);

#endif
