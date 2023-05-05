#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3/Administrator.h"
#include "../Lab3/Administrator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace BankTest
{
	TEST_CLASS(AdministratorTest)
	{
	public:
		TEST_METHOD(AddNewClientTest)
		{
			Client *testClient = new Client();
			Administrator testAdministrator;
			testAdministrator.addNewClient(testClient);
			Assert::AreEqual(1, (int)testAdministrator.getClientList().size());
		}

		TEST_METHOD(RemoveClientTest)
		{
			Client* testClient = new Client();
			Administrator testAdministrator;
			testAdministrator.addNewClient(testClient);
			Assert::AreEqual(1, (int)testAdministrator.getClientList().size());

			testAdministrator.removeClient(testClient->getId());
			Assert::AreEqual(0, (int)testAdministrator.getClientList().size());
		}

		TEST_METHOD(ChangeClientNameTest)
		{
			Client* testClient = new Client();
			Administrator testAdministrator;
			testAdministrator.addNewClient(testClient);
			string testName = "testName";

			testAdministrator.changeClientName(testClient->getId(), testName);

			Assert::AreEqual(testName, testClient->getName());
		}

		TEST_METHOD(ChangeClientSurnameTest)
		{
			Client* testClient = new Client();
			Administrator testAdministrator;
			testAdministrator.addNewClient(testClient);
			string testSurname = "testSurname";

			testAdministrator.changeClientSurname(testClient->getId(), testSurname);

			Assert::AreEqual(testSurname, testClient->getSurname());
		}

		TEST_METHOD(ChangeClientAccountNumberTest)
		{
			Client* testClient = new Client();
			Administrator testAdministrator;
			testAdministrator.addNewClient(testClient);
			long long testAccountNumber = generateAccountNumber();

			testAdministrator.changeClientAccountNumber(testClient->getId(), testAccountNumber);

			Assert::AreEqual(testAccountNumber, testClient->getAccountNumber());
		}

		TEST_METHOD(ChangeClientIncorrectAccountNumberTest)
		{
			Client* testClient = new Client();
			Administrator testAdministrator;
			testAdministrator.addNewClient(testClient);
			long long testAccountNumber = generateAccountNumber()%10;

			testAdministrator.changeClientAccountNumber(testClient->getId(), testAccountNumber);
			
			Assert::AreNotEqual(testAccountNumber, testClient->getAccountNumber());
		}

	};
}
