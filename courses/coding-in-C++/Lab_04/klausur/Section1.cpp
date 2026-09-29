#include <iostream>
#include <cmath>

class Vector{
private:
    double x;
    double y;
public:
    Vector() = default;
    Vector(double x, double y) : x(x), y(y){};
    double get_x() const{
        return x;
    }
    double get_y() const {
        return y;
    }
    void print(){
        std::cout << "X: " << x << std::endl;
        std::cout << "Y: " << y << std::endl;
        std::cout << std::endl;
    }
    double calculate_length(){
        double value = std::sqrt((x*x) + (y*y));
        return value;
    }
    double calculate_length(double precision){
        double value = std::sqrt((x*x) + (y*y));
        double factor = std::pow(10.0, precision);
        return std::round(value * factor) / factor;
    }
    Vector operator+(Vector &other){
        return Vector(x + other.get_x(), y+ other.get_y());
    };
    Vector operator+=(Vector &other){
        x = x + other.get_x();
        y = y + other.get_y();
    };
    Vector operator*(double scalar){
        return Vector(x * scalar, y * scalar);
    }
    bool operator>(Vector &other){
        if (x > other.get_x() && y > other.get_y())
        {
            return true;
        }
        return false;
        
    }
    bool operator==(Vector &other){
        if (x == other.get_x() && y == other.get_y())
        {
            return true;
        }
        return false;
        
    }
};

Vector operator*(double scalar, Vector &vector){
    return Vector(vector.get_x() * scalar, vector.get_y()*scalar);
}

int main(void){

}