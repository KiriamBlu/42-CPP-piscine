#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string fileName) {
	try {
		this->loadStorage(fileName, this->storage, ',', 0);
	}
	catch (std::runtime_error& err) {
		std::cout << err.what() << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange() {
}

size_t BitcoinExchange::size() {
	return this->storage.size();
}

std::vector<std::pair<std::string, float> >::iterator BitcoinExchange::getIterator() {
	return this->storage.begin();
}

std::ostream& operator<<(std::ostream& out, BitcoinExchange& exchange) {
	std::vector<std::pair<std::string, float> >::const_iterator it = exchange.getIterator();
	size_t total_length = exchange.size();

	for (size_t i = 0; i < total_length; i++) {
		out << it->first << " | " << it->second << std::endl;
		it++;
	}
	return out;
}

int BitcoinExchange::StringEraseAp(int start, int iteratorDir, std::string &aux, int character){
	int limiter = aux.length();
	int i = 0;
	start += iteratorDir;
	
	while(aux[start] == character && start >= 0 && start <= limiter){
		aux.erase(start, 1);
		if(iteratorDir == -1)
			start--;
		i++;
	}
	return(i);
}

////////////////////////////////////////Filters////////////////////////////////////////////////////

inline bool dateFormat(const std::string& input) {
	if (input.length() != 10) {
		return false;
	}

	if (input[4] != '-' || input[7] != '-') {
		return false;
	}

	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) {
			continue;
		}
		if (!isdigit(input[i])) {
			return false;
		}
	}
	//CHECK IF ITS POSIBLE
	return true;
}

void BitcoinExchange::crossValue(time_t date, float value){
	std::vector<std::pair<std::string, float> >::iterator it;
	time_t lastVal[2];

	memset(&lastVal, 0, sizeof(lastVal));
	for (it = this->getIterator(); it != this->storage.end(); it++) {
		lastVal[1] = convertDateToTime(it->first);
		if(lastVal[0] == 0)
			lastVal[0] = lastVal[1];
		if(lastVal[1] > date){
			std::cout << convertTimeToDate(lastVal[0]) << " "  << std::to_string(value) << " " << std::to_string((int)it->second * value) << std::endl;
			return	;
		}
		else{
			lastVal[0] = lastVal[1];
		}
	}	
} 

void BitcoinExchange::checkValues(std::string date, float value) {

	if (dateFormat(date) == BAD_FORMAT_DATE)
		throw std::runtime_error("Error: bad date => " + date );;

	if(value == BAD_INDEX)
		throw std::runtime_error("Error: bad input => " + date );

	if(value == BAD_NUMBER)
		throw std::runtime_error("Error: bad number");

	if(value == OUT_RANGE_NEGATIVE)
		throw std::runtime_error("Error: not a positive number.");

	if(value == OUT_RANGE_1000)
		throw std::runtime_error("Error: too large a number.");

	this->crossValue(convertDateToTime(date), value);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void BitcoinExchange::findAndCompare(std::vector<std::pair<std::string, float> > storage){
	std::vector<std::pair<std::string, float> >::iterator it;
	std::string str;
	float floatVal;

	(void)storage;

	for (it = storage.begin(); it != storage.end(); it++) {
		str = it->first;
		floatVal = it->second;
		try {
			checkValues(str, floatVal);
		}
		catch(std::runtime_error& err) {
			std::cout << err.what() << std::endl;
		}
	}
}

inline float getNumber(std::string numStr){
	float var;
	bool flag = true;
	unsigned long i = 0;

	while((isdigit(numStr[i]) || (numStr[i] == '.' && flag == true)) && numStr[i]){
		if (numStr[i] == '.')
			flag = false;
		i++;
	}
	if(numStr.length() != i)
		return BAD_NUMBER;

	var = stof(numStr);
	if (var > 1000) 
		return OUT_RANGE_1000;
	if (var < 0)
		return OUT_RANGE_NEGATIVE;
	return(var);
}

void BitcoinExchange::loadStorage(std::string fileName, std::vector<std::pair<std::string, float> >& storage, int limiter, bool flag = 0) {
	std::ifstream file(fileName);
	std::string str;
	std::string help[2];

	float var;
	struct tm aux;
	size_t pos;

	std::memset(&aux, 0, sizeof(aux));
	if (!file.is_open()) {
		throw std::runtime_error("Error: File could not be opened");
	}
	while (std::getline(file, str)) {
		pos = str.find((char)limiter);

		help[0] = str.substr(0, pos);
		help[1] = str.substr(pos + 1, str.length());

		if(flag == 1){
			if(help[0][help[0].length() - 1] == ' ')
				help[0].erase(help[0].length() - 1, 1);
			if(help[1][0] == ' ')
				help[1].erase(0, 1);
			var = getNumber(help[1]);
			if (str.length() < 14 || str.length() > 17)
				var = BAD_INDEX;
		}
		else
			var = stof(help[1]);
		storage.push_back(std::make_pair(help[0], var));
	}	
	file.close();
}

time_t BitcoinExchange::convertDateToTime(std::string help) {
	struct tm timeinfo;
	std::istringstream ss(help);
	time_t time;

	memset(&timeinfo, 0, sizeof(timeinfo));
	ss >> std::get_time(&timeinfo, "%Y-%m-%d");
	time = mktime(&timeinfo);

	return time;
}

std::string BitcoinExchange::convertTimeToDate(time_t time) {
	char buffer[11];
	struct tm* timeinfo;

	timeinfo = std::localtime(&time);
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);

	return std::string(buffer);
}
