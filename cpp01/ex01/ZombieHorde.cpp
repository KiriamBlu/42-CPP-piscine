
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){

	Zombie *newhorde;

	newhorde = NULL;
	if (N <= 0)
		std::cout << "Not able to summon this kind of horde" << std::endl;
	else
	{
		newhorde = new Zombie[N];
		for (int x; x < N; x++)
			newhorde[x].setzombiename(name);
	}
	return newhorde;
}