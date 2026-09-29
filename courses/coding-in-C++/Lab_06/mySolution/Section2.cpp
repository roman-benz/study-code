#include <iostream>
#include <stdlib.h>
#include <stdexcept>

class SensorFailureError : public std::runtime_error{
public:
    SensorFailureError() : std::runtime_error("Error: Sensor nicht verfügbar!"){};
}

class Sensor{
private:
    std::string name;
    double value;
    const double MIN_VALUE;
    const double MAX_VALUE;

public:
    Sensor(std::string name, const double MIN_VALUE, const double MAX_VALUE) : MIN_VALUE(MIN_VALUE), MAX_VALUE(MAX_VALUE){
        if (name == "")
        {
            throw std::invalid_argument("Error: Name is emtpy!");
        }
        if (MIN_VALUE >= MAX_VALUE)
        {
            throw std::invalid_argument("Error: Invalid MIN and MAX values");
        }
        this->name = name;
        this->value = 0;
    };

    void update_value(double value){
        if (value < MIN_VALUE || value > MAX_VALUE)
        {
            throw std::out_of_range("Error: Given value is out of range!");
        }
        this->value = value;
    };
    double get_value(){
        return value;
    };
    
    void print_info(){
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Value: " << this->value << std::endl;
        std::cout << "MIN, MAX" << this->MIN_VALUE << ", " << this->MAX_VALUE << std::endl;
    }
    void simulate_failure(){
        throw SensorFailureError();
    }


};



int main(void){
    try
    {
        Sensor temperatur("", 10, 90);
        Sensor humidity("Humidity", 0, 100);
        Sensor water_level("Water Level Sensor", 60, 50);

        humidity.update_value(-10);
    }

    catch(const std::invalid_argument &e){
        std::cerr << e.what() << '\n';
    }
    catch(const std::out_of_range &e){
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception &error)
    {
        std::cerr << error.what() << '\n';
    }
    
}