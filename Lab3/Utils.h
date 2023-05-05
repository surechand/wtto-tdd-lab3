#pragma once
#include <iostream>
#include <chrono>
#include <random>
using namespace std;

bool validateAmount(double amount);

string getCurrentDate();

bool validateAccountNumber(long long accountNumber);

int generateId();

long long generateAccountNumber();
