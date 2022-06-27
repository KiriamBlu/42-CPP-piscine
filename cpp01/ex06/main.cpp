
#include "Karen.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		std::cout << "Arguments cuality failed" << std::endl;
	else
		karenfilter(argv[1]);
	return 0;
}