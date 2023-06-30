#include "MutantStack.hpp"


int main()
{
	std::list<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top:";
	std::cout << mstack.top() << std::endl;
	
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

	mstack.pop();
	
	std::cout << "Size after pop: ";
	std::cout << mstack.size() << std::endl;

	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << "Despues de rellenar el contenido:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
	std::cout << "Ahora a ver si se copia a un stack del mismo tipo que mi MutantStack: " << std::endl;
	std::stack<int> s(mstack);

	while(!s.empty()){
		std::cout << s.top() << std::endl;
		s.pop();
	}
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
	return 0;
}

/*
#include <iostream>
#include <list>
#include <stack>

int main()
{
    std::list<int> mstack;
    
    mstack.push_back(5);
    mstack.push_back(17);
    
    std::cout << mstack.back() << std::endl;
    
    mstack.pop_back();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    
    //[...]
    mstack.push_back(0);
    
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
        
    return 0;
}
*/
