#include <iostream>
#include <limits>

namespace validation {
    bool isAdult(int age){
        if (age >= 18){           
            return true;
        }
        else{
            return false;
        }
    }
    bool isSenior(int age){
        if (age >= 65){
            return true;
        }
        else {
            return false;
        }
    }
}
int main() {
int alter;
std::cout << "Please enter your age: " << std::endl;
    if (!(std::cin >> alter))
    {
        std::cout << "Fehler: Das war keine Zahl." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
if (validation::isSenior(alter) == true)
{
    std::cout << "That means your an senior citizen." << std::endl;
}
else if (validation::isAdult(alter) == true)
{
    std::cout << "That means your an adult." << std::endl;
}
else if (validation::isAdult(alter) == false)
{
    std::cout << "That means your still an kid/teenager." << std::endl;
}

}