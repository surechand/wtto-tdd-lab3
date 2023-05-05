#include "Administrator.h"

Administrator::Administrator() {}

Administrator::~Administrator() {
	for (auto client : this->clientsList) {
		delete client;
	}
}

Client* Administrator::findClientById(int clientId) {
	for (Client* client : this->clientsList) {
		if (client->getId() == clientId) {
			return client;
		}
	}
	return nullptr;
}

void Administrator::addNewClient(Client *&newClient) {
	this->clientsList.push_back(newClient);
}

void Administrator::removeClient(int clientId) {
	std::vector<Client*>::iterator position;
	for (Client* client : this->clientsList) {
		position = std::find(this->clientsList.begin(), this->clientsList.end(), client);
		if (client->getId() == clientId && position != this->clientsList.end()) {
			this->clientsList.erase(position);
			delete client;
		}
	}
}

vector <Client*> Administrator::getClientList() {
	return this->clientsList;
}

void Administrator::getClientData(int clientId) {
	Client* client = findClientById(clientId);
	if (client != nullptr) {
		cout << "Id: " << client->getId() << endl;
		cout << "Name: " << client->getName() << endl;
		cout << "Surname: " << client->getSurname() << endl;
		cout << "Account Number: " << client->getAccountNumber() << endl;
		cout << "Account Balance: " << client->getAccountBalance() << endl;
	}
	else {
		cout << "Client doesn't exist" << endl;
	}
}

void Administrator::getClientOperationHistory(int clientId) {
	Client* client = findClientById(clientId);
	if (client != nullptr) {
		auto operationHistory = client->getOperationsHistory();
		for (auto &operation : operationHistory) {
			cout << operation.first << "\nAmount: " << operation.second << endl;
		}
	}
	else {
		cout << "Client doesn't exist" << endl;
	}
}

void Administrator::getClientOperationHistory(int clientId, int numOfLastOperations) {
	Client* client = findClientById(clientId);
	if (client != nullptr) {
		auto operationHistory = client->getOperationsHistory(numOfLastOperations);
		for (auto &operation : operationHistory) {
			cout << operation.first << "\nAmount: " << operation.second << endl;
		}
	}
	else {
		cout << "Client doesn't exist" << endl;
	}
}

void Administrator::changeClientName(int clientId, string name) {
	Client* client = findClientById(clientId);
	if (client != nullptr) {
		client->setName(name);
	}
	else {
		cout << "Client doesn't exist" << endl;
	}
}

void Administrator::changeClientSurname(int clientId, string surname) {
	Client* client = findClientById(clientId);
	if (client != nullptr) {
		client->setSurname(surname);
	}
	else {
		cout << "Client doesn't exist" << endl;
	}
}

void Administrator::changeClientAccountNumber(int clientId, long long accountNumber) {
	Client* client = findClientById(clientId);
	if (client != nullptr) {
		try {
			client->setAccountNumber(accountNumber);
		}
		catch (std::invalid_argument &err) {
			cerr << err.what() << endl;
		}
	}
	else {
		cout << "Client doesn't exist" << endl;
	}
}