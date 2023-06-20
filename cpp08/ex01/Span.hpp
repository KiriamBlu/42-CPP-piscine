
#ifndef SPAN_HPP
#define SPAN_HPP
#include <string>
#include <iostream>
#include <vector>
#include <exception>

class	Span {

	private:
		unsigned int		N;
		unsigned int		filled;
		std::vector<int>	storage;
	public:

		Span 			( void );
		Span 			( unsigned int N );
		Span 			( const Span & var );
		~Span			( void );
		Span &operator=	( const Span &tmp );
		int  &operator[]( unsigned int iter );

		void			addNumber( int number );
		void			addRange( int start, int end );
		void			addArrVector( std::vector<int> &vector );

		int				shortestSpan(void);
		int				longestSpan(void);

		class vectorIndexOutLimits : public std::exception {
			public:
				const char* throwException(const std::string& mensaje) const {
					return mensaje.c_str();
				}
		};


};

#endif
