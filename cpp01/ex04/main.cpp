
#include "replacer.hpp"

int main(int argc, char const *argv[])
{

	if (argc != 4)
		std::cerr << "This is not the right way to use this" << std::endl;
	else {

		replacer replacer;

		if (argv[1] && argv[2] && argv[3])
		{
			std::string file_n = argv[1];
			std::string one = argv[2];
			std::string two = argv[3];
			replacer.replace_in_file(file_n, one, two);
		}
		else
		{
			std::cerr << "Something is missing or wrong" << std::endl;
			exit (1);	
		}
	}
 	return 0;
}