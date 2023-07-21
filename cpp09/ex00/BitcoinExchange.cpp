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


bool BitcoinExchange::dateFormat(const std::string& input) {
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

int		BitcoinExchange::checkStrs(std::string *strings){
	size_t i = 0;

	if (dateFormat(strings[0]) == false){
		std::cout << "kk1" << std::endl;
		return(BAD_FORMAT_DATE);
	}
	try{
		std::stoi(strings[1]);
	}
	catch(std::out_of_range &err){
		std::cout << "kk2" << std::endl;
		return(BAD_NUMBER);
	}
	std::cout << strings[1] << std::endl;
	while(isdigit(strings[1][i]) && strings[1][i])
		i++;
	if(i != strings[1].length()){
		std::cout << "kk3" << std::endl;
		return(BAD_NUMBER);
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void	BitcoinExchange::loadStorage(std::string fileName, std::multimap<time_t, float> &storage, int limiter) {
	std::ifstream file(fileName);
	std::string str;
	int flag;
	std::string help[2];
	float var;
	struct tm aux;
	size_t pos;
	time_t time;

	
	std::memset(&aux, 0, sizeof(help[0]));
	if (!file.is_open()) {
		throw std::runtime_error("Error: File could not be opened");
	}
	while (std::getline(file, str)) {
		pos = str.find((char)limiter);


		this->StringEraseAp(pos, 1, str, ' ');
		pos -= this->StringEraseAp(pos, -1, str, ' ');

		help[0] = str.substr(0, pos);
		help[1] = str.substr(pos + 1, str.length());

		flag = this->checkStrs(help);

		if(flag == 0){
			std::istringstream ss(help[0]);
			ss >> std::get_time(&aux, "%Y-%m-%d");
			time = mktime(&aux);
			var = std::stof(help[1]);
		}
		else{
			if(flag == -1){
				time = flag;
				var = help[0].length();
			}
			else{
				time = flag;
				var = 0;
			}
		}

		
		storage.insert(std::make_pair(time, var));
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

