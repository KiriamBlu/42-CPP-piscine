#include "RPN.hpp"

int main(int argc, char **argv){
	if(argc != 2)
		std::cout << "ERROR: Too many args" << std::endl;
	else{
		std::string var(argv[1]);
		RPN aux(var);
		try{
			std::cout << aux.operate() << std::endl;
		}
		catch(std::runtime_error &err){
			std::cout << err.what() << std::endl;
		}
	}
}