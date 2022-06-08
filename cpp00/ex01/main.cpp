#include "contact_var.hpp"
#include "phonebook.hpp"

void lekas()
{
	system("leaks phonebook");
}

int	main(void)
{
	atexit(lekas);
	phonebook phbook;

	phbook.phonebook_start();
}
