#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3/Client.h"
#include "../Lab3/Client.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace BankTest
{
	TEST_CLASS(ClientTest)
	{
	public:
		TEST_METHOD(ConstructorBalance)
		{
			Client testClient;
			Assert::AreEqual(0.0, testClient.getAccountBalance());
		}

		TEST_METHOD(NameTest)
		{
			Client testClient;
			string name = "testName";
			testClient.setName(name);
			Assert::AreEqual(name, testClient.getName());
		}

		TEST_METHOD(SurnameTest)
		{
			Client testClient;
			string surname = "testName";
			testClient.setSurname(surname);
			Assert::AreEqual(surname, testClient.getSurname());
		}

		TEST_METHOD(ClientIdTest)
		{
			Client testClient;
			int newId = 12341234;
			testClient.setId(newId);
			Assert::AreEqual(newId, testClient.getId());
		}

		TEST_METHOD(IncorrectIdTest)
		{
			Client testClient;
			int newId = 123412345;
			auto func = [&testClient, newId] { testClient.setId(newId); };
			Assert::ExpectException<std::invalid_argument>(func);

			Client testClient2;
			int newId2 = 1234123;
			auto func2 = [&testClient2, newId2] { testClient2.setId(newId2); };
			Assert::ExpectException<std::invalid_argument>(func2);
		}

		TEST_METHOD(AtmDepositTest)
		{
			Client testClient;
			double amount = 1337.10;
			testClient.atmDeposit(amount);
			Assert::AreEqual(amount, testClient.getAccountBalance());
		}

		TEST_METHOD(IncorrectAtmDepositTest)
		{
			Client testClient;
			double amount = 1337.123;
			auto func = [&testClient, amount] { testClient.atmDeposit(amount); };
			Assert::ExpectException<std::invalid_argument>(func);

			Client testClient2;
			double amount2 = -1337.12;
			auto func2 = [&testClient2, amount2] { testClient2.atmDeposit(amount2); };
			Assert::ExpectException<std::invalid_argument>(func2);
		}

		TEST_METHOD(AccountNumberTest)
		{
			Client testClient;
			long long accountNumber = generateAccountNumber();
			testClient.setAccountNumber(accountNumber);
			Assert::AreEqual(accountNumber, testClient.getAccountNumber());
		}

		TEST_METHOD(IncorrectAccountNumberTest)
		{
			Client testClient;
			long long accountNumber = generateAccountNumber()%10;
			auto func = [&testClient, accountNumber] { testClient.setAccountNumber(accountNumber); };
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(AccountBalanceTest)
		{
			Client testClient;
			double accountBalance = 1337.10;
			testClient.setAccountBalance(accountBalance);
			Assert::AreEqual(accountBalance, testClient.getAccountBalance());
		}

		TEST_METHOD(IncorrectAccountBalanceTest)
		{
			Client testClient;
			double accountBalance = 1337.123;
			auto func = [&testClient, accountBalance] { testClient.setAccountBalance(accountBalance); };
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(CreditTest)
		{
			Client testClient;
			double amount = 1337.10;
			double interestRate = 5.6;
			testClient.getCredit(amount, interestRate);
			Assert::AreEqual(amount, testClient.getAccountBalance());
		}

		TEST_METHOD(IncorrectCreditTest)
		{
			Client testClient;
			double amount = 1337.123;
			double interestRate = 5.6;
			auto func = [&testClient, amount, interestRate] { testClient.getCredit(amount, interestRate); };
			Assert::ExpectException<std::invalid_argument>(func);

			Client testClient2;
			double amount2 = 1337.10;
			double interestRate2 = -5.6;
			auto func2 = [&testClient2, amount2, interestRate2] { testClient2.getCredit(amount2, interestRate2); };
			Assert::ExpectException<std::invalid_argument>(func2);
		}

	};
}