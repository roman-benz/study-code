#include <iostream>

class shape {
public:
    shape() = default;
    virtual double calculate_area() const {    //Virtual so function can be overwritten via override
        return 0.0;
    }
    virtual ~shape() {};

};

class circle : public shape{
private:
    double radius;

public:
    double calculate_area() const override {
        return 3.141 * radius * radius;
    }
    void setRadius(double &radius) {
        this->radius = radius;
    }
};

class rectangle : public shape{
private:
    double sideA;
    double sideB;

public:
    double calculate_area() const override {
        return sideA * sideB;
    }
    void setSides(double &sideA, double &sideB){
        this->sideA = sideA;
        this->sideB = sideB;
    }
};

int main(void) {
    const int arr_length = 4;

    circle myCircle;
    rectangle myRectangle;
    circle myCircle1;
    rectangle myRectangle1;

    double radius = 5.4;
    double sideA = 3.4;
    double sideB = 2.7;

    myCircle.setRadius(radius);
    myRectangle.setSides(sideA, sideB);
    myCircle1.setRadius(radius);
    myRectangle1.setSides(sideA, sideB);

    std::cout << myCircle.calculate_area() << std::endl;
    std::cout << myRectangle.calculate_area() << std::endl;

    //Part 3 Section 2
    shape* shapes[] = {&myCircle, &myRectangle, &myCircle1, &myRectangle1};

    for(int i = 0; i < arr_length; i++) {
        std::cout << shapes[i]->calculate_area() << std::endl;
    }


}