#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Iteradores para recorrer el contenido
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "Después de rellenar el contenido:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    std::cout << "Iteradores constantes:" << std::endl;
    MutantStack<int>::const_iterator cit = mstack.cbegin();
    MutantStack<int>::const_iterator cite = mstack.cend();

    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    std::cout << "Iteradores inversos:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    std::cout << "Iteradores constantes inversos:" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.crbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.crend();

    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        ++crit;
    }
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    return 0;
}

/*

int main()
{
    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << "Top: " << mlist.back() << std::endl;

    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    mlist.pop_back();

    std::cout << "Size after pop: " << mlist.size() << std::endl;

    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    // Iteradores para recorrer el contenido
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();

    ++it;
    --it;

    std::cout << "Después de rellenar el contenido:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    std::cout << "Iteradores constantes:" << std::endl;
    std::list<int>::const_iterator cit = mlist.cbegin();
    std::list<int>::const_iterator cite = mlist.cend();

    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    std::cout << "Iteradores inversos:" << std::endl;
    std::list<int>::reverse_iterator rit = mlist.rbegin();
    std::list<int>::reverse_iterator rite = mlist.rend();

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    std::cout << "Iteradores constantes inversos:" << std::endl;
    std::list<int>::const_reverse_iterator crit = mlist.crbegin();
    std::list<int>::const_reverse_iterator crite = mlist.crend();

    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        ++crit;
    }
    std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

    return 0;
}

*/
