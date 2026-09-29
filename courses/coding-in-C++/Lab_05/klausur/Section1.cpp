#include <iostream>

template <typename T>
void swap(T value1, T value2){
    T temp = value1;
    value1 = value2;
    value2 = temp;
}

template <typename T, int size>
void print_sensor_frame(T (&array)[size]){
    for (int i = 0; i < size i++)
    {
        std::cout << array[i] << " ";
    }
    
}

template <typename T, int size>
void find_smalles_element(T (&array)[size]){
    T smallest = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < smallest)
        {
            smallest = array[i];
        }
        
    }
    
}

template <typename T1, typename T2>
void print_pair(std::string label1, T1 value1, std::string label2, T2 value2){
    std::cout << label1 << ": " << value1 << "| " << label2 << ": " << value2 << std::endl;
}