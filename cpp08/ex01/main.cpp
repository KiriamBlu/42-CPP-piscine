#include "Span.hpp"
#include <random>

#define TESTNUM 25000

std::vector<int> fillVectorWithNums(unsigned int size){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(-100000, 100000);
	std::vector<int> vec;

	for (unsigned int i = 0; i < size; i++) 
		vec.push_back(dist(mt));

	return vec;
}

int main()
{
	try{

		int 		*values;
		
		Span sp = Span(TESTNUM);/*
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);


		std::cout << "Filled:" << sp.getFilled() << " - To fill:" << TESTNUM - sp.getFilled() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan();
		values = (sp.getNumbers()); 
		std::cout << " numbers: n1=(" << values[0] << ") n2=(" << values[1] << ")"  <<std::endl;
		std::cout << "Longest span: " << sp.longestSpan();
		values = (sp.getNumbers()); 
		std::cout << " numbers: n1=(" << values[0] << ") n2=(" << values[1] << ")"  <<std::endl;

		sp.addRange(8, 14);

		std::cout << "Filled:" << sp.getFilled() << " - To fill:" << TESTNUM - sp.getFilled() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan();
		values = (sp.getNumbers()); 
		std::cout << " numbers: n1=(" << values[0] << ") n2=(" << values[1] << ")"  <<std::endl;
		std::cout << "Longest span: " << sp.longestSpan();
		values = (sp.getNumbers()); 
		std::cout << " numbers: n1=(" << values[0] << ") n2=(" << values[1] << ")"  <<std::endl;

		std::vector<int> numbers;
		numbers.push_back(15);
		numbers.push_back(8);
		numbers.push_back(6);
		numbers.push_back(1);

		sp.addArrVector(numbers);//16

		std::cout << "Element at index 2: " << sp[2] << std::endl;
		std::cout << "Element at index 5: " << sp[5] << std::endl;



		std::cout << "Filled:" << sp.getFilled() << " - To fill:" << TESTNUM - sp.getFilled() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan();
		values = (sp.getNumbers()); 
		std::cout << " numbers: n1=(" << values[0] << ") n2=(" << values[1] << ")"  <<std::endl;
		std::cout << "Longest span: " << sp.longestSpan();
		values = (sp.getNumbers()); 
		std::cout << " numbers: n1=(" << values[0] << ") n2=(" << values[1] << ")"  <<std::endl;*/

		
		std::vector<int> random = fillVectorWithNums(TESTNUM - 16);

		sp.addArrVector(random);
		sp.printValues();

		std::cout << "Filled:" << sp.getFilled() << " - To fill:" << TESTNUM - sp.getFilled() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan();
		values = (sp.getNumbers()); 
		std::cout << " numbers: n1=(" << values[0] << ") n2=(" << values[1] << ")"  <<std::endl;
		std::cout << "Longest span: " << sp.longestSpan();
		values = (sp.getNumbers()); 
		std::cout << " numbers: n1=(" << values[0] << ") n2=(" << values[1] << ")"  <<std::endl;
		
	}
    catch (const Span::vectorIndexOutLimits &ex) {
		std::cout << "Exception caught: " << ex.throwException() << std::endl;
  	}
  	catch (const Span::noSpaceLeft &ex) {
		std::cout << "Exception caught: " << ex.throwException() << std::endl;
  	}
  	catch (const Span::invalidRange &ex) {
		std::cout << "Exception caught: " << ex.throwException() << std::endl;
  	}
  	catch (const Span::notEnoughNumbers &ex) {
		std::cout << "Exception caught: " << ex.throwException() << std::endl;
  	}
  	catch (const Span::emptyVector &ex) {
		std::cout << "Exception caught: " << ex.throwException() << std::endl;
  	}

  return 0;
}
