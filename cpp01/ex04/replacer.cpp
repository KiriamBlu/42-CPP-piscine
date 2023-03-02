
#include "replacer.hpp"


void	replacer::replace_in_file( std::string file, std::string one, std::string two){

	std::ifstream infile;
	std::stringstream aux;
	std::string goback;

	infile.open( file, std::ifstream::in );
	if (infile.fail())
	{
		std::cerr << "Something failed while opening the file" << std::endl;
		exit (1);
	}
	aux << infile.rdbuf();
	goback = aux.str();
	infile.close();
	std::ofstream outfile;
	outfile.open( file.append("2"), std::ofstream::out );
	if (outfile.fail())
	{
		std::cerr << "Something failed while opening the second file" << std::endl;
		exit (1);
	}
	while( goback.find(one) < goback.length() )
	{
		outfile << goback.substr(0, goback.find(one));
		outfile << two;
		if ( (goback.find(one) + one.length()) !=  goback.length())
			goback = goback.substr(goback.find(one) + one.length(), goback.length());
		else
			break;
	}
	outfile << goback.substr(0, goback.length());
	outfile.close();
}

replacer::replacer(void){}

replacer::~replacer(void){}