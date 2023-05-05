#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Utils.h"
using namespace std;

class Client
{
private:
	int id;

	string name, surname;

	long long accountNumber;

	double accountBalance = 0.0;

	vector <pair<string, double>> operationHistory;

public:

	Client();

	Client(string name, string surname, long long accountNumber);

	Client(string name, string surname, long long accountNumber, double accountBalance);

	Client(int id, string name, string surname, long long accountNumber, double accountBalance);

	void setId(int id);
	int getId();

	void setName(string name);
	string getName();

	void setSurname(string surname);
	string getSurname();

	void setAccountNumber(long long accountNumber);
	long long getAccountNumber();

	void setAccountBalance(double accountBalance);
	double getAccountBalance();

	void atmDeposit (double amount);

	pair<double, long long> sendMoneyTransfer (double amount, long long receiverAccountNumber);

	void receiveMoneyTransfer(double amount, long long receiverAccountNumber);

	void getCredit (double amount, double interestRate);

	vector <pair<string, double>> getOperationsHistory ();

	vector <pair<string, double>> getOperationsHistory (int numOfLastOperations);

	~Client();
};

