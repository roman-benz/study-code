#include <iostream>
#include <cmath>

class Vector2D {
private:
    double x;
    double y;
public:
    Vector2D() = default;
    Vector2D(double x, double y) : x(x), y(y){};
    void set_x(double x){
        this->x = x;
    };
    void set_y(double y){
        this->y = y;
    };
    double get_x(){
        return x;
    };
    double get_y(){
        return y;
    }
    void print_vector(){
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
    };
    double calculate_length(){
        return std::sqrt( ( (this->x)*(this->x) ) + ( (this->y)*(this->y) ) );
    }
    double calculate_length(int precision){
        double value = std::sqrt( ( (this->x)*(this->x) ) + ( (this->y)*(this->y) ) );
        double factor = std::pow(10.0, precision);
        return std::round(value * factor) / factor;
    }
    Vector2D operator+(Vector2D &other){
        return Vector2D(x+other.x, y+other.y);
    };
    void operator+=(Vector2D &other){
        x += other.x;
        y += other.y;
    };
    Vector2D operator*(double scalar){
        return Vector2D(x*scalar, y*scalar);
    };

};
Vector2D operator*(double scalar, Vector2D &vector){
    return vector * scalar;
};

int main(void){
    Vector2D vector(2, 5);
    Vector2D vector1(3, 1);
    vector.print_vector();

    Vector2D newvector = vector * 2;
    newvector.print_vector();

    vector += newvector;
    vector.print_vector();

    newvector = vector1 + vector;
    newvector.print_vector();

}