
#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	(void)argv;

	if(argc < 2 || argc > 2 ){
		std::cout << ( argc  < 2 ? "Err no input file parameter" : "Err too many inputs")<< std::endl;
		return 0;
	}

	try{
		std::vector<std::pair<std::string, float> >	auxStorage;

		BitcoinExchange btc("data.csv");
		btc.loadStorage(std::string(argv[1]), auxStorage, '|', 1);

		btc.findAndCompare(auxStorage);
	}
	catch(std::runtime_error &err){
		std::cout << err.what() << std::endl; 
	}
}