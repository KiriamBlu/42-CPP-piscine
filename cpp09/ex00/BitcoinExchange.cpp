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
	std::cout << "Destructor called" << std::endl;
}

size_t BitcoinExchange::size() {
	return this->storage.size();
}

std::multimap<time_t, float>::iterator BitcoinExchange::getIterator() {
	return this->storage.begin();
}

std::ostream& operator<<(std::ostream& out, BitcoinExchange& exchange) {
	std::multimap<time_t, float>::const_iterator it = exchange.getIterator();
	size_t total_length = exchange.size();

	for (size_t i = 0; i < total_length; i++) {
		out << exchange.convertTimeToDate(it->first) << " | " << it->second << std::endl;
		it++;
	}
	return out;
}

/*bool BitcoinExchange::parseInsert(std::string str){


	storage.insert(std::make_pair(time, std::stof(str.substr(pos + 1, str.length()))));
}*/

void BitcoinExchange::loadStorage(std::string fileName, std::multimap<time_t, float> &storage, int limiter) {
	std::ifstream file(fileName);
	std::string str;
	struct tm aux;
	size_t pos;
	time_t time;

	std::memset(&aux, 0, sizeof(aux));
	if (!file.is_open()) {
		throw std::runtime_error("Error: File could not be opened");
	}
	while (file >> str) {
		pos = str.find((char)limiter);
		
		std::cout << "(" << str.substr(0, pos) << ")" << std::endl;
		
		std::istringstream ss(str.substr(0, pos));

		std::cout << ss << std::endl;
		
		ss >> std::get_time(&aux, "%Y-%m-%d");
		time = mktime(&aux);

		std::cout << time << std::endl;

		try{
			std::cout << std::stof(str.substr(pos + 1, str.length())) << std::endl;
		}
		catch(std::invalid_argument &err){
			std::cout << "kk" << std::endl;
		}

		storage.insert(std::make_pair(time, std::stof(str.substr(pos + 1, str.length()))));
		//parseInsert(str, );
  	}	
	file.close();
}

std::string BitcoinExchange::convertTimeToDate(time_t time) {
    char buffer[11];
    struct tm* timeinfo;

    timeinfo = std::localtime(&time);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);

    return std::string(buffer);
}