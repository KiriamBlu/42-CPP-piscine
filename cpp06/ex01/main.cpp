#include <iostream>

struct Data {
    int value1;
    float value2;
    char value3;
};


uintptr_t serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw){	
	return reinterpret_cast<Data *>(raw);
}

int	main(void){
	
	Data data;
	Data *after;
	uintptr_t aux;

	data.value1 = 42;
	data.value2 = 42.3f;
	data.value3 = '*';

	std::cout << "Before serialize: ";
	std::cout << &data << std::endl;

	std::cout << "Int pointer value: ";
	aux = serialize(&data);
	std::cout << aux << std::endl;

	std::cout << "After serialize: ";
	after = deserialize(aux);
	std::cout << after << std::endl;

	std::cout << "Result: ";
	if(&data == after)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}