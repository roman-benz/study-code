#include <iostream>
#include <cmath>

class Vector {
private:
    double x;
    double y;
public: 
    Vector();
    Vector(double x, double y) : x(x), y(y){};
    double const getX(){
        return x;
    }
    double const getY(){
        return y;
    }
    void const print(){
        std::cout << "X: " << x << std::endl;
        std::cout << "Y: " << y << std::endl;
    }

    double calculate_length(){
        double value = std::sqrt(x*x + y*y);
        return value;
    }
    double calculate_length(int precision){
        double value = std::sqrt(x*x + y*y);
        double factor = std::pow(10.0, precision);
        return std::round(value * factor) / factor;
    }
    Vector operator+(const Vector& v) {
        return Vector(x + v.x, y + v.y);
    }
    Vector& operator+=(const Vector& v) {
        x = x + v.x;
        y = y + v.y;
        return *this;
    }
    Vector operator*(double scalar){
        return Vector(x * scalar, y * scalar);
    }

};

int main (void) {
    Vector a(1.456, 5.324);
    Vector b(3.2326, 1.93328);
    std::cout << a.calculate_length() << std::endl;
    std::cout << a.calculate_length(3) << std::endl;
    
    (a += b).print();
}