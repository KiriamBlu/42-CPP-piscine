#include "RPN.hpp"

int main(int argc, char **argv){
	std::string var(argv[1]);
	
	if(argc != 2)
		std::cout << "ERROR: Too many args" << std::endl;
	else{
		RPN aux(var);
		try{
			aux.operate();
		}
		catch(std::runtime_error &err){
			std::cout << err.what() << std::endl;
		}
	}
}