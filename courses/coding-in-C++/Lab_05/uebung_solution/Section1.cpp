#include <iostream>

template <typename T>
void swap_values(T &value1, T &value2){
    T temp = value1;
    value1 = value2;
    value2 = temp;
};

template <typename T, int size>
void print_sensor_frame(T (&array)[size]){
    for (int i = 0; i < size; i++)
    {
        if (i == size-1)
        {
            std::cout << array[i];
        }
        else{
            std::cout << array[i] << ", ";
        }
        
    }
    std::cout << std::endl;
    
}

template <typename T, int size>
T find_weakest_signal(T (&array)[size]){
    T smallest_element;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < smallest_element)
        {
            smallest_element = array[i];
        }
        
        
    }
    return smallest_element;
}

template <typename T1, typename T2>
void print_pair(std::string label1, T1 value1, std::string label2, T2 value2){
    std::cout << label1 << ": " << value1 << " | " << label2 << ": " << value2 << std::endl;
    
}

int main(void){
    int value1 = 5;
    int value2 = 1;
    swap_values(value1, value2);
    std::cout << "V1: " << value1 << " V2: " << value2 << std::endl;

    int array[5] = {5, 4, 3, 2, 1};
    print_sensor_frame(array);
    std::cout << "Smalles element in array: " << find_weakest_signal(array) << std::endl;
}