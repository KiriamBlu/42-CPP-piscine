
#include "Base.hpp"
#include <iostream>

int main() {
    Base* obj = generate();
    filter(obj);

    delete obj;

    return 0;
}
