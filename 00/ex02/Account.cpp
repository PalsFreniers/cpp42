#include "Account.hpp"
#include <iostream>

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit) {
        _nbDeposits = 0;
        _nbWithdrawals = 0;
        _accountIndex = _nbAccounts;
        _nbAccounts++;
        _totalAmount += initial_deposit;
        _amount = initial_deposit;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp() {
        std::cout << "[19920104_091532] ";
}

int Account::getNbAccounts() {
        return _nbAccounts;
}

int Account::getNbDeposits() {
        return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
        return _totalNbWithdrawals;
}

int Account::getTotalAmount() {
        return _totalAmount;
}

void Account::displayAccountsInfos() {
        _displayTimestamp();
        std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount <<
                     ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
        int pa = _amount;
        _nbDeposits++;
        _totalNbDeposits++;
        _amount += deposit;
        _totalAmount += deposit;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << pa << ";deposit:" << deposit <<
                     ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

int Account::checkAmount() const {
        return _amount;
}

bool Account::makeWithdrawal(int withdrawal) {
        if(_amount - withdrawal < 0) {
                _displayTimestamp();
                std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
                return false;
        }
        int pa = _amount;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";p_amount:" << pa << ";withdrawal:" << withdrawal <<
                     ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
}

void Account::displayStatus() const {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
