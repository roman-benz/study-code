#include <iostream>

class DrinkBuilder
{
private:
    std::string name;
    int sugar;
    int temperature;
    bool withMilk;
    constexpr int maxTemp = 100;
public:
    DrinkBuilder();
    DrinkBuilder setName(const std::string& name){
        this->name = name;
        return *this;
    };
    DrinkBuilder setSugar(int sugar){
        this->sugar = sugar;
        return *this;
    };
    DrinkBuilder setTemperature(int temperature){
        this->temperature = temperature;
        return *this;
    };
    DrinkBuilder setWithMilk(bool withMilk){
        this->withMilk = withMilk;
        return *this;
    };
};

int main(void){
    DrinkBuilder builder;
    builder.setName("BobaTea").setSugar(10).setTemperature(60).setWithMilk(true);
}

