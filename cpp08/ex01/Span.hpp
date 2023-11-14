
#ifndef SPAN_HPP
#define SPAN_HPP
#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class	Span {

	private:
		unsigned int		_N;
		unsigned int		_filled;
		std::vector<int>	_storage;
		int 				_numbers[2];
	public:

		Span 			( void );
		Span 			( unsigned int N );
		Span 			( const Span & var );
		~Span			( void );

		Span &operator=	( const Span &tmp );
		int  &operator[]( unsigned int iter );

		unsigned int 	getFilled(void) const ;
		int       		getN(void) const;
		int				*getNumbers(void);
		int   			getNumberIndex( unsigned int index ) const;

		void			addNumber( int number );
		void			addRange( int start, int end );
		void			addArrVector( std::vector<int> &vector );

		int				shortestSpan( void );
		int				longestSpan( void );

		void 			printValues( void ) const;

		class vectorIndexOutLimits : public std::exception {
			public:
				const std::string throwException() const {
					return "Index out of range";
				}
		};

		class noSpaceLeft : public std::exception {
			public:
				const std::string throwException() const {
					return "No space left";
				}
		};

		class invalidRange : public std::exception {
			public:
				const std::string throwException() const {
					return "Invalid range";
				}
		};
		
		class notEnoughNumbers : public std::exception {
			public:
				const std::string throwException() const {
					return "Not enough numbers for span";
				}
		};
		
		class emptyVector : public std::exception {
			public:
				const std::string throwException() const {
					return "This vector is empty";
				}
		};
};

#endif
