
#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
		std::cout << "Arguments cuality failed" << std::endl;
	else
		Harlfilter(argv[1]);
	return 0;
}