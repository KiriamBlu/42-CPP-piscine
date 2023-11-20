
#include "BitcoinExchange.hpp"

#define FILE "NOT_INCLUDE_ON_PUSH/data.csv"

int main(int argc, char **argv){
	(void)argv;

	if(argc < 2 || argc > 2 ){
		std::cout << ( argc  < 2 ? "Err no input file parameter" : "Err too many inputs")<< std::endl;
		return 0;
	}

	try{
		BitcoinExchange btc(FILE);
		//std::cout << btc;
		btc.findAndCompare(std::string(argv[1]));
	}
	catch(std::runtime_error &err){
		std::cout << err.what() << std::endl; 
	}
}