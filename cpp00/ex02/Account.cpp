#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//------------------------GETTERS---------------------------------

int	Account::checkAmount(void) const {

	return this->_amount ;

}

int	Account::getNbAccounts(void) {

	return Account::_nbAccounts ;

}

int	Account::getTotalAmount(void) {

	return Account::_totalAmount ;

}

int	Account::getNbDeposits(void) {

	return Account::_totalNbDeposits ;

}

int	Account::getNbWithdrawals(void) {

	return Account::_totalNbWithdrawals ;

}

void displayer ( std::string type, int number, bool finish ){
	std::cout << type << number;
	if ( finish == 1 )
		std::cout << ";";
	else
		std::cout << std::endl;
}

void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	displayer ("accounts:", Account::getNbAccounts(), 1);
	displayer ("total:", Account::getTotalAmount(), 1);
	displayer ("deposits:", Account::getNbDeposits(), 1);
	displayer ("withdrawals:", Account::getNbWithdrawals(), 0);
}

void	Account::displayStatus( void ) const{

	_displayTimestamp();
	displayer ("index:", this->_accountIndex, 1);
	displayer ("amount:", this->checkAmount(), 1);
	displayer ("deposits:", this->_nbDeposits, 1);
	displayer ("withdrawals:", this->_nbWithdrawals, 0);
}

void	Account::_displayTimestamp( void ){

	std::time_t	now = time(0);
	std::tm *local_time = std::localtime(&now);

	std::cout << "[";
	std::cout << local_time->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << local_time->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << local_time->tm_mday << '_';
	std::cout << std::setfill('0') << std::setw(2) << local_time->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << local_time->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << local_time->tm_sec;
	std::cout << "]" << ' '; 
}

Account::Account ( int initial_deposit ){ 

	_displayTimestamp();
	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbAccounts += 1;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	displayer ("index:", this->_accountIndex, 1);
	displayer ("amount:", this->checkAmount(), 1);
	std::cout << "created" << std::endl;
}

Account::~Account ( void ){

	_displayTimestamp();
	displayer ("index:", this->_accountIndex, 1);
	displayer ("amount:", this->checkAmount(), 1);
	std::cout << "closed" << std::endl;

}

void	Account::makeDeposit( int deposit ){

	_displayTimestamp();
	Account::_totalNbDeposits += 1;
	displayer ("index:", this->_accountIndex, 1);
	displayer ("p_amount:", this->checkAmount(), 1);
	this->_amount += deposit;
	this->_nbDeposits += 1;
	this->_totalAmount += deposit;
	displayer ("deposit:", deposit, 1);
	displayer ("amount:", this->checkAmount(), 1);
	displayer ("nb_deposits:", this->_nbDeposits, 0);
}

bool	Account::makeWithdrawal( int withdrawal ){

	_displayTimestamp();
	displayer ("index:", this->_accountIndex, 1);
	displayer ("p_amount:", this->checkAmount(), 1);
	if ( withdrawal > this->checkAmount() )
	{
		std::cout << "withdrawal:refused" << std::endl;
		return 0;
	}
	else
	{
		Account::_totalNbWithdrawals += 1;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		this->_amount -= withdrawal;
		displayer ("withdrawal:", withdrawal, 1);
		displayer ("amount:", this->_amount, 1);
		displayer ("nb_withdrawals:", this->_nbWithdrawals, 0);
	}
	return (1);
}


