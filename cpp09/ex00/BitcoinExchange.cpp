#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string fileName) {
	try {
		this->loadStorage(fileName, this->storage, ',');
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
		out << exchange.convertTimeToDate(it->first) << " | " << it->second << std::endl;
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

	return true;
}

void BitcoinExchange::checkStrs(std::string date, float value) {

	if (dateFormat(date) == false)
		throw std::runtime_error("");;

	
	if(value == -1)
		throw std::runtime_error("");

	if(value == -2)
		throw std::runtime_error("String out of index");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void BitcoinExchange::findAndCompare(std::vector<std::pair<std::string, float> > storage){
	std::vector<std::pair<std::string, float> >::iterator it[2];
	std::string str_pair[2];
	float float_pair[2];

	(void)storage;

	for (it[1] = storage.begin(); it[1] != storage.end(); it[1]++) {
		str_pair[REMOTE] = it[1]->first;
		float_pair[REMOTE] = it[1]->second;

		try {
			for (it[0] = this->getIterator(); it[0] != this->storage.end(); it[0]++) {
				str_pair[LOCAL] = it[0]->first;
				float_pair[LOCAL] = it[0]->second;
			}
		}
		catch(std::runtime_error& err) {
			std::cout << err.what() << std::endl;
		}
	}
}

void BitcoinExchange::loadStorage(std::string fileName, std::vector<std::pair<std::string, float> >& storage, int limiter) {
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

		help[0] = str.substr(0, pos - 1);
		help[1] = str.substr(pos + 2, str.length());
		std::cout << help[1] << std::endl;

		try {
			var = stof(help[1]); //ADD TRY	
		}
		catch(...) {
			var = -1;
		}
		if (str.length() < 14 && str.length() > 17)
			var = -2;
		if (var < 0 || var > 1000) {
			var = -1;
		}
		storage.push_back(std::make_pair(help[0], var));
	}	
	file.close();
}

time_t BitcoinExchange::convertTimeToDate(std::string help) {
	struct tm timeinfo;
	time_t time;

	std::istringstream ss(help);
	ss >> std::get_time(&timeinfo, "%Y-%m-%d");
	time = mktime(&timeinfo);

	return time;
}
