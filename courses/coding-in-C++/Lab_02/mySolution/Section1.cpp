#include <iostream>

class BankAccount {
    private:
        std::string owner;
        double balance;
    public:
        void setOwner(std::string newowner){
            owner = newowner;
        }
        std::string getOwner(){
            return owner;
        }
        void deposit(double amount);
        void withdraw(double amount);
        double getBalance(){
            return balance;
        }
        void getAccountInfo(){
            std::cout << "Owner: " << owner << std::endl;
            std::cout << "Balance: " << balance << "€" << std::endl;
        }

};

void  BankAccount :: deposit(double amount){
    if (amount > 0)
    {
        balance = balance + amount;
    }
}

void BankAccount :: withdraw(double amount){
    if ((balance - amount) > 0)
    {
        balance = balance - amount;
    }
    
}

int main(void){
    BankAccount meinKonto;
    meinKonto.setOwner("Roman Benz");
    meinKonto.deposit(50);
    meinKonto.withdraw(40);
    std::cout << "Balance: " << meinKonto.getBalance() << std::endl;
    meinKonto.withdraw(11);
    std::cout << "Balance: " << meinKonto.getBalance() << std::endl;

}