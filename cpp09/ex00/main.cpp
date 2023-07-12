
#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	(void)argv;

	if(argc < 2 || argc > 2 ){
		std::cout << ( argc  < 2 ? "Err no input file parameter" : "Err too many inputs")<< std::endl;
		return 0;
	}

	try{
		std::multimap<time_t, float>	auxStorage;

		BitcoinExchange btc("data.csv");
		//std::cout << btc << std::endl;
		std::cout<< std::endl << std::endl << std::endl;
		btc.loadStorage(std::string(argv[1]), auxStorage, '|');
	}
	catch(std::runtime_error &err){
		std::cout << err.what() << std::endl; 
	}
}