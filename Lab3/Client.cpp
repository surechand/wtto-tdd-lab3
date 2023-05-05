#include "Client.h"

Client::Client(){
	this->id = generateId();
}

Client::~Client(){}

Client::Client(string name, string surname, long long accountNumber) {
	if (!validateAccountNumber(accountNumber)) {
		throw std::invalid_argument("incorrect accountNumber");
	}
	this->id = generateId();
	this->name = name;
	this->surname = surname;
	this->accountNumber = accountNumber;
	this->accountBalance = 0.0;
}

Client::Client(string name, string surname, long long accountNumber, double accountBalance) {
	if (!validateAmount(accountBalance)) {
		throw std::invalid_argument("incorrect decimal places");
	}
	if (!validateAccountNumber(accountNumber)) {
		throw std::invalid_argument("incorrect accountNumber");
	}
	this->id = generateId();
	this->name = name;
	this->surname = surname;
	this->accountNumber = accountNumber;
	this->accountBalance = accountBalance;
}

Client::Client(int id, string name, string surname, long long accountNumber, double accountBalance) {
	if (!validateAmount(accountBalance)) {
		throw std::invalid_argument("incorrect decimal places");
	}
	if (!validateAccountNumber(accountNumber)) {
		throw std::invalid_argument("incorrect accountNumber");
	}
	if (id >= 10000000 && id <= 99999999) {
		throw std::invalid_argument("incorrect client id");
	}
	this->id = id;
	this->name = name;
	this->surname = surname;
	this->accountNumber = accountNumber;
	this->accountBalance = accountBalance;
}


void Client::setId(int id) {
	if (id >= 10000000 && id <= 99999999) {
		this->id = id;
	}
	else {
		throw std::invalid_argument("id must contain 8 digits");
	}
}

int Client::getId() {
	return this->id;
}

void Client::setName(string name) {
	this->name = name;
}

string Client::getName() {
	return this->name;
}

void Client::setSurname(string surname) {
	this->surname = surname;
}

string Client::getSurname() {
	return this->surname;
}

void Client::setAccountNumber(long long accountNumber) {
	if (!validateAccountNumber(accountNumber)) {
		throw std::invalid_argument("incorrect accountNumber");
	}
	this->accountNumber = accountNumber;
}

long long Client::getAccountNumber() {
	return this->accountNumber;
}

void Client::setAccountBalance(double accountBalance) {
	if (!validateAmount(accountBalance)) {
		throw std::invalid_argument("incorrect decimal places");
	}
	this->accountBalance = accountBalance;
}

double Client::getAccountBalance() {
	return this->accountBalance;
}

void Client::atmDeposit(double amount) {
	if (amount <= 0) {
		throw std::invalid_argument("amount is smaller or equal 0");
	}
	else if (!validateAmount(amount)) {
		throw std::invalid_argument("incorrect decimal places");
	}
	this->accountBalance += amount;
	ostringstream balanceStream;
	balanceStream << std::fixed << setprecision(2) << this->accountBalance;
	this->operationHistory.push_back(make_pair(getCurrentDate() + " ATM Deposit" + " balance: " + balanceStream.str(), amount));
};

pair<double, long long> Client::sendMoneyTransfer(double amount, long long receiverAccountNumber) {
	if (amount <= 0) {
		throw std::invalid_argument("amount is smaller or equal 0");
	}
	else if (!validateAmount(amount)) {
		throw std::invalid_argument("incorrect decimal places");
	}
	else if (this->accountBalance >= amount) {
		this->accountBalance -= amount;
		ostringstream balanceStream;
		balanceStream << std::fixed << setprecision(2) << this->accountBalance;
		this->operationHistory.push_back(make_pair(getCurrentDate() + " money transfer to " + to_string(receiverAccountNumber) + " balance: " + balanceStream.str(), -amount));
		return make_pair(amount, receiverAccountNumber);
	}
	else {
		throw std::exception("insufficient funds");
	}
};

void Client::receiveMoneyTransfer(double amount, long long receiverAccountNumber) {
	this->accountBalance += amount;
	ostringstream balanceStream;
	balanceStream << std::fixed << setprecision(2) << this->accountBalance;
	this->operationHistory.push_back(make_pair(getCurrentDate() + " money transfer from " + to_string(receiverAccountNumber) + " balance: " + balanceStream.str(), amount));
};


void Client::getCredit(double amount, double interestRate) {
	if (amount <= 0) {
		throw std::invalid_argument("amount is smaller or equal 0");
	}
	else if (!validateAmount(amount)) {
		throw std::invalid_argument("incorrect decimal places");
	}
	else if (interestRate <= 0) {
		throw std::invalid_argument("interestRate is smaller or equal 0");
	}
	this->accountBalance += amount;
	ostringstream balanceStream;
	balanceStream << std::fixed << setprecision(2) << this->accountBalance;
	this->operationHistory.push_back(make_pair(getCurrentDate() + " credit given with interest rate " + to_string(interestRate) + " balance: " + balanceStream.str(), amount));
};

vector <pair<string, double>> Client::getOperationsHistory() {
	return this->operationHistory;
}

vector <pair<string, double>> Client::getOperationsHistory(int numOfLastOperations) {
	vector <pair<string, double>> lastOperations(numOfLastOperations);

	//kopiuje n podanych elementów lub wszystkie je¿eli liczba operacji jest mniejsza od podanej
	copy_n(this->operationHistory.rbegin(), min(this->operationHistory.size(), vector <pair<string, double>>::size_type(numOfLastOperations)), lastOperations.begin());
	return lastOperations;
}
