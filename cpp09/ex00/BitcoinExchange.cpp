#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string fileName) {
	try {
		this->loadStorage(fileName);
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

void BitcoinExchange::loadStorage(std::string fileName) {
	std::ifstream file(fileName);
	std::string str;
	struct tm aux;
	size_t pos;
	time_t time;

	if (!file.is_open()) {
		throw std::runtime_error("Error: File could not be opened");
	}
	file >> str;
	while (file >> str) {
    pos = str.find(",");
    std::istringstream ss(str.substr(0, pos));
    ss >> std::get_time(&aux, "%Y-%m-%d");
    time = mktime(&aux);
    std::cout << str.substr(pos + 1, str.length()) << std::endl;
    storage.insert(std::make_pair(time, std::stof(str.substr(pos + 1, str.length()))));
  }

	file.close();
}

std::string BitcoinExchange::convertTimeToDate(time_t time) {
    char buffer[10];
    struct tm* timeinfo;

    timeinfo = std::localtime(&time);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);

    return std::string(buffer);
}