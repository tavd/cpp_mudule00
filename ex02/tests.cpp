// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>     // for std::time and std::localtime
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size(sizeof(amounts) / sizeof(int));//8, number of elements
	//declares a std::vector<Account> variable named accounts using the range constructor.
	//creates Account objects and inits them with the elements from amounts
	accounts_t				accounts(amounts, amounts + amounts_size);
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	//declares a std::vector<int> called deposits and initializes it with the elements from the array d[].
	ints_t				deposits(d, d + d_size);
	ints_t::iterator	dep_begin	= deposits.begin();//iterator pointing to the first element of the deposits vector.
	ints_t::iterator	dep_end		= deposits.end();//iterator pointing to one past the last element of the deposits vector.

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

Account::displayAccountsInfos();
//Iterates through all Account objects in the vector accounts, from acc_begin to acc_end.
//For each Account object, it calls the displayStatus() member function.
// &Account::displayStatus - a pointer to the displayStatus member function of the Account class.
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
//acc_int_t it(acc_begin, wit_begin); creates an object it of type std::pair<accounts_t::iterator, ints_t::iterator>
//and initializes it with acc_begin and wit_begin. This line calls the std::pair constructor that takes
//two arguments (one for each member of the pair). It initializes it.first with acc_begin and it.second with wit_begin.
//     The loop processes both vectors simultaneously:
//     For each Account object in the accounts vector, it calls the makeDeposit method, 
// passing the corresponding deposit amount from the deposits vector.
	for ( acc_int_t it( acc_begin, dep_begin );//init: it.first=acc_begin, it.second=dep_begin
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {
		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();

	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {
		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
