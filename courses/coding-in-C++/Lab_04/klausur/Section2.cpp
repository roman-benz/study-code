#include <iostream>

class Shape{
private:
public:
    virtual double calculate_area(){
        return 0.0;
    }
    virtual ~Shape() = default;
};

class Circle : public Shape{
private:
    double radius;
public:
    Circle(double radius) : radius(radius){};
    double calculate_area() override {
        return 3.141 * radius * radius;
    };
    
};

class Rectangle : public Shape{
private:
    double a;
    double b;
public:
    Rectangle(double a, double b) : a(a), b(b){};
    double calculate_area() override {
        return a*b;
    };
    
};

int main(void){
    Circle myCircle1(5);
    Circle myCircle2(5);
    Rectangle myRectangle1(5, 4);
    Rectangle myRectangle2(5, 4);
    Shape* array[] = {&myCircle1, &myCircle2, &myRectangle1, &myRectangle2};
    for (int i = 0; i < 4; i++)
    {
        std::cout << array[i]->calculate_area() << std::endl;
    }
    
}