
#include "templates.hpp"

int main( void ) {

    int a = 2;
    int b = 3;

    ::swap( a, b );

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);

    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    float l = 3.3;
    float m = 4.4;

    ::swap(l, m);

    std::cout << "l = " << l << " , m = " << m << std::endl;
    std::cout << "min( l, d ) = " << ::min( l, m ) << std::endl;
    std::cout << "max( l, d ) = " << ::max( l, m ) << std::endl;

    void *var1 = &l;
    void *var2 = &m;

    ::swap(var1, var2);

    std::cout << "var1 = " << var1 << " , var2 = " << var2 << std::endl;
    std::cout << "min( var1, var2 ) = " << ::min( var1, var2 ) << std::endl;
    std::cout << "max( var1, var2 ) = " << ::max( var1, var2 ) << std::endl;

    return 0;
}