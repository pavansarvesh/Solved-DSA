// References : https://www.youtube.com/watch?v=W1CjYKmTB-c

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
public: // public makes it access outside the class
    string name;
    int balance;
};

void main()
{
    BankAccount account1;
    account1.name = "Pavan";
    account1.balance = 3000;
}// c program ti insert a number in a given array of size n = 10 position is 2