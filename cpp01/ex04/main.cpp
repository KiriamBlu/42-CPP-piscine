
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char const *argv[])
{
	std::stringstream aux;
	std::string goback;

	if (argc != 4)
		std::cerr << "This is not the right way to use this" << std::endl;
	else {

		if (argv[1] && argv[2] && argv[3])
		{
			std::string file_n = argv[1];
			std::string one = argv[2];
			std::string two = argv[3];
			std::ifstream infile;
			infile.open( file_n, std::ifstream::in );
			if (infile.fail())
			{
				std::cerr << "Something failed while opening the file" << std::endl;
				exit (1);
			}
			aux << infile.rdbuf();
			goback = aux.str();
			infile.close();
			std::ofstream outfile;
			outfile.open( file_n.append("2"), std::ofstream::out );
			if (outfile.fail())
			{
				std::cerr << "Something failed while opening the second file" << std::endl;
				exit (1);
			}
			std::istringstream iss(goback);
			do{
				std::string helper;

				iss >> helper;
				if ( !helper.compare(one) )
					outfile << one;
				else if ( !helper.compare(two) )
					outfile << two;
				else
					outfile << helper;
			}while (iss);
		}
		else
		{
			std::cerr << "Something is missing or wrong" << std::endl;
			exit (1);
		}
	}
 	return 0;
}