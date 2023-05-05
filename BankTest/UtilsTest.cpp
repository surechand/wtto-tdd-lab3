#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab3/Utils.h"
#include "../Lab3/Utils.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace BankTest
{
	TEST_CLASS(UtilsTest)
	{
	public:		
		TEST_METHOD(validateAmountNoDecimalPlaces)
		{
			double amount = 100;
			bool result = validateAmount(amount);
			Assert::IsTrue(result);
		}

		TEST_METHOD(validateAmountThreeDecimalPlaces)
		{
			double amount = 100.123;
			bool result = validateAmount(amount);
			Assert::IsFalse(result);
		}

		TEST_METHOD(generateAccountNumberRange)
		{
			long long accountNumber = generateAccountNumber();
			Assert::IsTrue(accountNumber >= 100000000000);
			Assert::IsTrue(accountNumber <= 999999999999);
		}

		TEST_METHOD(generateIdRange)
		{
			int accountNumber = generateId();
			Assert::IsTrue(accountNumber >= 10000000);
			Assert::IsTrue(accountNumber <= 99999999);
		}

		TEST_METHOD(validateAccountNumberTest)
		{
			long long accountNumber = generateAccountNumber();
			bool result = validateAccountNumber(accountNumber);
			Assert::IsTrue(result);

			result = validateAccountNumber(accountNumber % 10);
			Assert::IsFalse(result);

			result = validateAccountNumber(accountNumber * 10);
			Assert::IsFalse(result);
		}

	};
}
