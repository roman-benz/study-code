#include <iostream>
#include <exception>

class Sensor{
private:
    std::string name;
    double value;
    const double MIN_VALUE;
    const double MAX_VALUE;

public:
    Sensor(std::string name, double value, double MIN_VALUE, double MAX_VALUE) : name(name), value(value), MIN_VALUE(MIN_VALUE), MAX_VALUE(MAX_VALUE){
        if (MIN_VALUE > MAX_VALUE || MIN_VALUE == MAX_VALUE)
        {
            throw std::invalid_argument("MIN- and MAX_VALUE is an invalid pair.");
            if (value > MAX_VALUE || value < MIN_VALUE)
            {
                throw std::out_of_range("Value outside of allowed range.");
            }
            
        }
        
    };
    void update_value(double value){
        if (value > MAX_VALUE || value < MIN_VALUE)
        {
            throw std::out_of_range("Value outside of allowed range.");
        }
        else{
            this->value = value;
        }
    };
    double get_value(){
        return this->value;
    };
    void print_info(){
        std::cout << name << " | " << value << std::endl;
    };
};

class SensorFailureError : public std::runtime_error {
private:
public:
    SensorFailureError() : std::runtime_error("Sensor is unreachable"){};
};


int main(void){
    try{
    //Sensor temp1("Temperatur", 10, -50, 200);
    Sensor temp2("Temperatur", 10, 500, 200);
    Sensor temp3("Temperatur", 10, 500, 500);
    Sensor temp4("Temperatur", 10, 500, 500);
    //temp1.update_value(-51);
    }
    catch(const std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    }
    catch(const std::out_of_range& e){
        std::cout << e.what() << std::endl;
    }


    
}