#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
    
void print_vector(std::vector<int> &flight_data){
    for (int data : flight_data)
    {
        std::cout << data << " ";
    }
    std::cout << std::endl;
    
}

void sort_data(std::vector<int> &flight_data){
    std::sort(flight_data.begin(), flight_data.end());
    print_vector(flight_data);
}

template <typename T>
void find_data(std::vector<int> &flight_data, T data){
    auto it = std::find(flight_data.begin(), flight_data.end(), data);
    if (it != flight_data.end())
    {
        std::cout << data << "Gefunden!" << std::endl;
    }
    else{
        std::cout << "Data " << data << "Nicht gefunden!" << std::endl;
    }
    
}

int main(void){
    std::vector<int> flight_data = {42, 17, 42, 5, 99, 17, 63, 12};
    print_vector(flight_data);
    sort_data(flight_data);
    print_vector(flight_data);
    find_data(flight_data, 5);
    find_data(flight_data, 6);
}

