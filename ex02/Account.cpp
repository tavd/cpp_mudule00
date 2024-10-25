#include <iostream>
#include <iomanip>
#include "Account.hpp"

//Even though they are initialized to zero, you typically want to explicitly initialize static members for clarity and control.
int Account::_nbAccounts = 0;//getters setters for the static fields?
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{}

Account::Account(int initial_deposit)
{
	//8 accounts created:
	//[19920104_091532] index:0;amount:42;created
	//[19920104_091532] index:7;amount:16576;created
	_displayTimestamp();
	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;//amount in all accounts
	_nbAccounts++;
	std::cout<<"index:"<<_accountIndex<<";"<<"amount:"<<checkAmount()<<";"<<"created"<<std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
// Within the class scope: When you are inside a static member function, like Account::getNbAccounts(), 
// you are already in the class scope. This means the compiler knows that _nbAccounts refers to the static member of the Account class.
// Access to static fields: Since both the static function (getNbAccounts()) and the static field (_nbAccounts) 
// belong to the same class, there’s no need to qualify _nbAccounts with the class name inside the function.
int Account::checkAmount(void) const
{
	return _amount;
}

void Account::_displayTimestamp(void)
{
	// time_t is a data type in C/C++ used to represent calendar time.
	// It's typically the number of seconds that have passed since the Unix epoch (January 1, 1970, 00:00:00 UTC).
	time_t current_time = std::time(NULL);
	//struct tm is a structure that holds the components of calendar time, such as year, month, day, hour, minute, and second.
	// std::localtime(&now) converts the time_t value into a tm structure, which represents the local time. 
	// This allows you to break down the time_t value into human-readable components like year, month, day, etc.
	struct tm timenow = *std::localtime(&current_time);
	std::cout<<"["<<timenow.tm_year + 1900
	<<std::setfill('0')<<std::setw(2)
	<<timenow.tm_mon + 1
	<<std::setfill('0')<<std::setw(2)
	<<timenow.tm_mday<<"_"
	<<std::setfill('0')<<std::setw(2)
	<<timenow.tm_hour
	<<std::setfill('0')<<std::setw(2)
	<<timenow.tm_min
	<<std::setfill('0')<<std::setw(2)
	<<timenow.tm_sec<<"] ";
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
//private static fields are accessible from public static functions within the same class
void Account::displayAccountsInfos( void )
{
		_displayTimestamp();
		std::cout<<"accounts:"<<_nbAccounts<<";"<<"total:"<<_totalAmount<<";"//getNbAccounts()
		<<"deposits:"<<_totalNbDeposits<<";"
		<<"withdrawals:"<<_totalNbWithdrawals<<std::endl;
}

//19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"<<"amount:"<<_amount<<";"<<"deposits:"<<_totalNbDeposits<<";"
	<<"withdrawals:"<<_totalNbWithdrawals<<std::endl;
}
//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"<<"p_amount:"<<_amount<<";"
	<<"deposit:"<<deposit<<";";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout<<"amount:"<<_amount<<";"<<"nb_deposits:"<<_nbDeposits<<std::endl;
}
//[19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
// [19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
// [19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"<<"p_amount:"<<_amount<<";";
	if (_amount < withdrawal)
	{
		std::cout<<"withdrawal:refused"<<std::endl;
		return false;
	}
	// else
	// {
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout<<"withdrawal:"<<withdrawal<<";""amount:"<<_amount<<";"<<"nb_withdrawals:"<<_nbWithdrawals<<std::endl;
	return true;
	// }
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout<<"index:" <<_accountIndex<<";"<<
	"amount:" <<checkAmount()<<";"<<
	"closed"<<std::endl;
}
