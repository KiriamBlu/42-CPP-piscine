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
	BAD_FORMAT_DATE = 0,
	BAD_INDEX = -1,
	BAD_NUMBER = -2,
	OUT_RANGE_NEGATIVE = -3,
	OUT_RANGE_1000 = -4
};

class	BitcoinExchange {

	private:
		std::vector<std::pair<std::string, float> > storage;

		int 													StringEraseAp(int start, int iteratorDir, std::string &aux, int character);
		void													checkValues(std::string date, float value);
		void 													crossValue(time_t date, float value);

	public:
		BitcoinExchange	( void );
		BitcoinExchange	( std::string fileName );
		~BitcoinExchange( void );

		size_t 													size(void);
		std::vector<std::pair<std::string, float> >::iterator 	getIterator(void);
		time_t													convertDateToTime(std::string time);
		std::string 											convertTimeToDate(time_t time);

		void													findAndCompare(std::vector<std::pair<std::string, float> > storage);
		void 													loadStorage(std::string fileName, std::vector<std::pair<std::string, float> >& storage, int limiter, bool flag);


};
std::ostream& operator<<(std::ostream& out, BitcoinExchange& exchange);

#endif
