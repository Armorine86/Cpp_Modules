/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:42:08 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/21 13:20:19 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	
	_amount = 0;
	_accountIndex = _nbAccounts++;
	_amount += initial_deposit;
	this->_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account() {
	
	_accountIndex = _nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {

	this->_displayTimestamp();
	_nbAccounts--;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::makeDeposit(int deposit) {
	
	_displayTimestamp();
	std::cout << "index" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << std::endl;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal; 
	if (_amount < withdrawal)
	{
		std::cout << ":refused\n";
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << ";amount:" << _amount << ";nb_withdrawal:" << _nbWithdrawals << std::endl;
	return (true);
}

void Account::displayStatus(void) const {
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << '\n';
}

void Account::displayAccountsInfos() {
	
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
	
	time_t timenow = time(0);
	struct tm local_time;
	char buffer[80];
	
	local_time = *localtime(&timenow);
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", &local_time);
	std::cout << buffer;
}
