#include <iostream>
#include <math.h>

class BankAccount {
private:
    std::string owner;
    double balance;
public:
    void setOwner(std::string name){
        this->owner = name;
    };
    std::string getOwner(){
        return owner;
    };
    void deposit(double amount){
        this->balance += amount;
    };
    void withdraw(double amount){
        if ((this->balance) -amount > 0)
        {
            std::cout << "Not enough balance to withdraw" << std::endl; 
        }
        
    };
    double getBalance(){
        return this->balance;
    };
    void getAccountInfo(){
        std::cout << "Owner: " << owner << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    };
};