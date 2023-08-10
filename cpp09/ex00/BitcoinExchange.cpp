#include "BitcoinExchange.hpp"


///////////////////////////////////CLASS-STUFF////////////////////////////////////////
BitcoinExchange::BitcoinExchange(std::string fileName) {
	try {
		this->loadStorage(fileName, this->storage);
	}
	catch (std::runtime_error& err) {
		std::cout << err.what() << std::endl;
	}
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


BitcoinExchange::~BitcoinExchange() {
}

std::ostream& operator<<(std::ostream& out, BitcoinExchange& exchange) {
	std::map<std::string, float>::const_iterator it;
	for (it = exchange.getIterator(0); it != exchange.getIterator(1); ++it) {
		out << it->first << " | " << it->second << std::endl;
	}
	return out;
}



////////////////////////////////////////Filters////////////////////////////////////////////////////

static inline bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static inline bool isValidDate(int day, int month, int year) {
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 1 || month < 1 || month > 12 || day < 1) {
		return false;
	}

	if (isLeapYear(year)) {
		daysInMonth[2] = 29;
	}

	return day <= daysInMonth[month];
}

static inline bool dateFormat(const std::string& input) {
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

	int year = std::stoi(input.substr(0, 4));
	int month = std::stoi(input.substr(5, 2));
	int day = std::stoi(input.substr(8, 2));

	return isValidDate(day, month, year);
}


static inline float getNumber(std::string numStr){
	float var;
	bool flag = true;
	unsigned long i = 0;

	while((isdigit(numStr[i]) || (numStr[i] == '.' && flag == true) || numStr[i] == '-') && numStr[i]){
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


////////////////////////////////////////////AUXILIARS/////////////////////////////////////////////////

size_t BitcoinExchange::size() {
	return this->storage.size();
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

static inline std::string cleanValue(std::string var){
	size_t i, f;

	i = 0;
	f = var.length() - 1;
	while((var[f] == '0' || var[f] == '.') && f > 0){
		i++;
		f--;
	}
	var.erase(var.length() - i, i);
	return var;
}

std::map<std::string, float>::iterator BitcoinExchange::getIterator(bool flag = false) {
	if(flag == false)
		return this->storage.begin();
	else
		return this->storage.end();
}


/////////////////////////////////////////////MAIN-FUNCTIONS/////////////////////////////////////////////////////


void BitcoinExchange::findAndCompare(std::string fileName){
	std::ifstream file(fileName);
	std::string help[2];
	float floatVal;
	int pos;
	std::string str;

	std::getline(file, str);
	while (std::getline(file, str)) {
		pos = str.find('|');
		help[0] = "";

		if(pos != -1){
			help[0] = str.substr(0, pos);
			help[1] = str.substr(pos + 1, str.length());
			help[0].erase(help[0].length() - 1, 1);
			help[1].erase(0, 1);

			floatVal = getNumber(help[1]);
		}
		else
			floatVal = BAD_INDEX;
		if (str.length() < 14 || str.length() > 17)
			floatVal = BAD_INDEX;
		try {
			this->checkValues(help[0], floatVal);
		}
		catch(std::runtime_error& err) {
			std::cout << err.what() << std::endl;
		}
	}
	file.close();
}
 

void BitcoinExchange::checkValues(std::string date, float value) {

	if (dateFormat(date) == BAD_FORMAT_DATE)
		throw std::runtime_error("Error: bad date => " + date );;

	if(value == BAD_INDEX)
		throw std::runtime_error("Error: bad input => " + date );

	if(value == BAD_NUMBER)
		throw std::runtime_error("Error: bad number");

	if(value == OUT_RANGE_NEGATIVE)
		throw std::runtime_error("Error: not a positive number. ");

	if(value == OUT_RANGE_1000)
		throw std::runtime_error("Error: too large a number.");

	this->crossValue(convertDateToTime(date), value);
}


void BitcoinExchange::crossValue(time_t date, float value) {
    std::map<std::string, float>::iterator it;
    time_t lastVal[2];
    float var;

    memset(&lastVal, 0, sizeof(lastVal));
    for (it = this->getIterator(); it != this->storage.end(); ++it) {
        lastVal[1] = convertDateToTime(it->first);
        if (lastVal[1] > date) {
            if (std::abs(lastVal[0] - date) > std::abs(lastVal[1] - date)) {
                char valueBuffer[32];
                sprintf(valueBuffer, "%f", value);

                char productBuffer[32];
                sprintf(productBuffer, "%f", var * value);

                std::cout << convertTimeToDate(lastVal[1]) << " => " << cleanValue(std::string(valueBuffer)) << " = " << cleanValue(std::string(productBuffer)) << std::endl;
            } else {
                char valueBuffer[32];
                sprintf(valueBuffer, "%f", value);

                char productBuffer[32];
                sprintf(productBuffer, "%f", it->second * value);

                std::cout << convertTimeToDate(lastVal[0]) << " => " << cleanValue(std::string(valueBuffer)) << " = " << cleanValue(productBuffer) << std::endl;
            }
            return;
        } else {
            lastVal[0] = lastVal[1];
            var = it->second;
        }
    }
}

void BitcoinExchange::loadStorage(std::string fileName, std::map<std::string, float>& storage) {
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
        pos = str.find(',');

        help[0] = str.substr(0, pos);
        help[1] = str.substr(pos + 1, str.length());
        var = atof(help[1].c_str());
        storage.insert(std::make_pair(help[0], var));
    }
    file.close();
}




