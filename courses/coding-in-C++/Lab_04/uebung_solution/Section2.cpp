#include <iostream>

class Shape{
private:
public:
    virtual double calculate_area() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    private:
    double radius;

    public:
    Circle(double radius) : radius(radius){};
    double calculate_area() override {
        return 3.141 * radius * radius;
    };
    ~Circle() override = default;
};

class Rectangle : public Shape {
    private: 
    double x;
    double y;

    public:
    Rectangle(double x, double y) : x(x), y(y){};
    double calculate_area() override{
        return x*y;
    };
    ~Rectangle() = default;
};

int main(void){
    

    Circle myCircle1(5);
    Circle myCircle2(4);
    std::cout << "Circle area: " << myCircle1.calculate_area() << std::endl;

    Rectangle myRectangle1(3, 4);
    Rectangle myRectangle2(4, 3);
    std::cout << "Rectangle area: " << myRectangle1.calculate_area() << std::endl;

    Shape* myshapes[4] = {&myCircle1, &myCircle2, &myRectangle1, &myRectangle2};
    for (int i = 0; i < 4; i++)
    {
        std::cout << myshapes[i]->calculate_area() << std::endl;
    }
    
    
    
}