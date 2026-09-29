#include <iostream>
#include <cstdint>
#include <limits>


void readScore(uint_fast16_t &score)
{
    const int MAX_SCORE = 100;
    while(true)
    {
        if (!(std::cin >> score))
        {
            std::cout << "Error: Invalid Number. Try Again.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (score > 100)
        {
            std::cout << "Error: Number out of Range. Try Again.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;

    }
    
}
void readStudentData(std::string &name, uint_fast16_t &homework, uint_fast16_t &midterm, uint_fast16_t &finalExam)
{
    std::cout << "Enter Student Name: " << std::endl;
    std::cin >> std::ws;
    if(!std::getline(std::cin, name))
    {
        std::cout << "An error occured while reading student name!";
    }
    std::cout << "Enter Homework score: ";
    readScore(homework);

    std::cout << "Enter Midterm score: ";
    readScore(midterm);

    std::cout << "Enter Final exam score: ";
    readScore(finalExam);

}



int main(void)
{
    std::string name;
    uint_fast16_t homework;
    uint_fast16_t midterm;
    uint_fast16_t finalExam;

    readStudentData(name, homework, midterm, homework);
    std::cout << name << " " << homework << " " << midterm << " " << finalExam << std::endl;
}