
#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>

class	Brain {

	protected:
		std::string _ideas[100];
	public:

		Brain ( void );
		Brain ( const Brain & var );
		~Brain ( void );

		std::string	get_idea( unsigned int number ) const;
		void		set_idea( unsigned int number, std::string new_idea );
		Brain		&operator=(const Brain &tmp);
};

#endif
