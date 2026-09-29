#include <iostream>

constexpr int DEFAULT_TEMP = 60;

class Drink{
private:
    std::string name;
    int sugar;
    int temperature = DEFAULT_TEMP;
    int maxSugar = 100;
    bool withMilk;
public:
    Drink& setName(const std::string &name){
        this->name = name;
        return *this;
    }
    Drink& setSugar(int sugar){
        this->sugar = sugar;
        return *this;
    }
    Drink& setTemperature(int temperature){
        this->temperature = temperature;
        return *this;
    }
    Drink& setWithMilk(bool withMilk){
        this->withMilk = withMilk;
        return *this;
    };
    
}