#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cstring>

enum identifyer{
	LOCAL = 0,
	REMOTE
};

enum errorStatus{
	BAD_FORMAT_DATE = 0,
	BAD_INDEX = -1,
	BAD_NUMBER = -2,
	OUT_RANGE_NEGATIVE = -3,
	OUT_RANGE_1000 = -4
};

class BitcoinExchange {

private:
	std::map<std::string, float> storage;

	int StringEraseAp(int start, int iteratorDir, std::string &aux, int character);
	void checkValues(std::string date, float value, std::string str);
	void crossValue(time_t date, float value);

public:
	BitcoinExchange( void );
	BitcoinExchange( std::string fileName );
	~BitcoinExchange( void );

	size_t size(void);
	std::map<std::string, float>::iterator getIterator(bool flag);
	time_t convertDateToTime(std::string time);
	std::string convertTimeToDate(time_t time);

	void findAndCompare(std::string fileName);
	void loadStorage(std::string fileName, std::map<std::string, float>& storage);

};

std::ostream& operator<<(std::ostream& out, BitcoinExchange& exchange);

#endif
