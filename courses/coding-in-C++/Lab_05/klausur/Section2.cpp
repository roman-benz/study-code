#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
void print_data(std::vector<T> &vector){
    for(auto it = vector.begin(); it != vector.end(); ++it)
    {
       std::cout << *it << " ";
       
    }    
    std::cout << std::endl;
    
}

template <typename T>
void task7(std::vector<T> &vector){

    std::replace(vector.begin(), vector.end(), -1, 0);
    print_data(vector);

    int count8 = std::count(vector.begin(), vector.end(), 8);
    std::cout << count8 << std::endl;

    std::reverse(vector.begin(), vector.end());
    print_data(vector);
    
}


int main(void){
    std::vector<int> vector1 = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    task7(vector1);
}