#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "Client.h"
using namespace std;

class Administrator
{
private:
	vector <Client*> clientsList;

	Client* findClientById(int clientId);
	
public:
	Administrator();

	void addNewClient(Client *&newClient);

	void removeClient(int clientId);

	vector <Client*> getClientList();

	void getClientData(int clientId);

	void getClientOperationHistory(int clientId);

	void getClientOperationHistory(int clientId, int numOfLastOperations);

	void changeClientName(int clientId, string name);

	void changeClientSurname(int clientId, string surname);

	void changeClientAccountNumber(int clientId, long long accountNumber);

	~Administrator();
};
