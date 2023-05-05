#include "Utils.h"

bool validateAmount(double amount) {
	string amount_str = to_string(amount);
	int len = amount_str.find_last_of('.');
	amount_str.erase(0, len + 1 + 2);
	if (stoi(amount_str) == 0) {
		return true;
	}
	else {
		return false;
	}
}

string getCurrentDate() {
	//c++ 20
	using namespace std::chrono;
	auto local = zoned_time{ current_zone(), system_clock::now() };
	auto dateStr = format("{}", local);

	return dateStr;
}


/*
* Returns true if account number is valid.
*/
bool validateAccountNumber(long long accountNumber) {
	//check if number contains 12 digits
	string accountNumberStr = to_string(accountNumber);

	if (accountNumberStr.length() != 12 || accountNumberStr.find('.') != std::string::npos) {
		return false;
	}
	else {
		bool parity = false;
		while (accountNumber)
		{
			parity = !parity;
			accountNumber = accountNumber & (accountNumber - 1);
		}
		return parity;
	}
}

int generateId() {
	std::random_device rd{};
	std::mt19937 engine{ rd() };

	std::uniform_int_distribution<int> dist{ 10000000, 99999999 };

	int newId = dist(engine);

	return newId;
}

long long generateAccountNumber() {
	std::random_device rd{};
	std::mt19937 engine{ rd() };

	std::uniform_int_distribution<long long> dist{ 100000000000, 999999999999 };

	long long newAccountNumber;

	do {
		newAccountNumber = dist(engine);
	} while (!validateAccountNumber(newAccountNumber));

	return newAccountNumber;
}