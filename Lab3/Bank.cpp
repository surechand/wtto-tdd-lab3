// Lab3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Bank.h"
#include "Administrator.h"
#include "Client.h"
#include "Utils.h"
using namespace std;

void moneyTransfer(double amount, Client* &sender, Client* &receiver) {
    try {
        pair<double, long long> receiverData = sender->sendMoneyTransfer(amount, receiver->getAccountNumber());
        receiver->receiveMoneyTransfer(amount, sender->getAccountNumber());
    }
    catch (const std::invalid_argument &err) {
        cerr << err.what() << endl;
    }
    catch (const std::exception &err) {
        cerr << err.what() << endl;
    }
}

int main()
{
    std::cout << "Welcome to the world's worst bank" << endl;

    Client* client1 = new Client("Janusz", "Kowalski", generateAccountNumber());
    Client* client2 = new Client("Jan", "Nowak", generateAccountNumber());

    Administrator* administrator = new Administrator();

    administrator->addNewClient(client1);
    administrator->addNewClient(client2);

    auto id1 = client1->getId();
    auto id2 = client2->getId();

    try {
        client1->atmDeposit(500.21);
        client2->atmDeposit(750.45);
    }
    catch (std::invalid_argument &err) {
        cout << err.what() << endl;
    }

    administrator->getClientData(id1);
    administrator->getClientData(id2);

    cout << client1->getAccountBalance() << endl;
    cout << client2->getAccountBalance() << endl;

    cout << endl;

    moneyTransfer(150.12, client1, client2);


    cout << "1 po przelewie " << client1->getAccountBalance() << endl;
    cout << "2 po przelewie " << client2->getAccountBalance() << endl;

    cout << endl;

    administrator->getClientOperationHistory(client1->getId());

    delete client1, client2, administrator;

    return 0;
}

