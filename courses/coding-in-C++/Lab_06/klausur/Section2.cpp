#include <iostream>
#include <exception>

class SensorFailureError : public std::runtime_error{
private:
public:
    SensorFailureError(std::string error_msg) : std::runtime_error(error_msg){}; 
};

class Sensor{
private:
    std::string name;
    double value;
    const double MIN_VALUE;
    const double MAX_VALUE;
public:
    Sensor(std::string name, double value, double MIN_VALUE, double MAX_VALUE) : name(name), value(value), MIN_VALUE(MIN_VALUE), MAX_VALUE(MAX_VALUE){
        if (name.size() == 0)
        {   
            throw std::invalid_argument("Name ist empty");
        }
        if (value < MIN_VALUE || value > MAX_VALUE)
        {
            throw std::out_of_range("Sensor value out of bounds.");
        }
        
        
    };
    void update_value(double value){
        if (value < MIN_VALUE || value > MAX_VALUE)
        {
            throw std::out_of_range("Sensor value out of bounds.");
        }
        this->value = value;
    }
    double get_value(){
        return this->value;
    }

    void print_info(){
        std::cout << name << " | " << value << std::endl;
    }

    void simulate_failure(){
        throw SensorFailureError("This is a test");
    };
};

int main(void){
    try
    {
        Sensor mine("H", 1, 0, 100);
        mine.simulate_failure();
    }
    catch(const std::invalid_argument &e){
        std::cout << e.what() << std::endl;
    }
    catch(const std::out_of_range &e){
        std::cout << e.what() << std::endl;
    }
    catch(const SensorFailureError &e){
        std::cout << e.what() << std::endl;
    }
    
    

}