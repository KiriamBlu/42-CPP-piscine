
#include <iostream>

template <typename arr, typename funct>
void iter(arr &array, int lenght, funct function){
	for (int i = 0; i < lenght; ++i)
		function(array[i]);
}

