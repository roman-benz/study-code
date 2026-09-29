#include <string>
#include <iostream>

class BankAccount{
private:
    std::string owner;
    double balance;
public:
    void setOwner(std::string owner){
        this->owner = owner;
    }
    std::string getOwner(){
        return this->owner;
    }
    void deposit(double amount){
        if (amount >= 0)
        {
            balance += amount;
        }
        
    }
    void withdraw(double amount){
        if ((balance - amount) > 0)
        {
            balance -= amount;
        }
        
    }
    double getBalance(){
        return this->balance;
    }
    void getAccountInfo(){
        std::cout << "Owner: " << owner << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    };
};