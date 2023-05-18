 
#include "converter.hpp"


int main(int argc, char* argv[]) {

	Converter 	converter;

    if (argc > 1) {
    	converter.fillValue(argv[1]);
    	std::cout << converter;
    } else {
        std::cout << "No se ingresaron parámetros." << std::endl;
    }

    return 0;
}
