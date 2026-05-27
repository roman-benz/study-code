#include <stdlib.h>
#include <iostream>

template <typename T>
void swap_parameters(T& data1, T& data2){
    std::cout << "Before Swap (Data1, Data2): " << data1 << ", " << data2 <<std::endl;
    T temp = data1;
    data1 = data2;
    data2 = temp;
    std::cout << "After (Data1, Data2): " << data1 << ", " << data2 << std::endl;
}

template <typename T, const int size>
void print_sensor_frame(T(&array)[size]){
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
}

template <typename T, const int size>
T return_smallest_value(T(&array)[size]){
    T smallest_value = array[0];
    if (size <= 1){
        return array[0];
    }
    
    for (int i = 0; i < size; i++)
    {
        if (i+1 < size)
        {
            if (array[i] < array[i+1])
            {
                if (array[i] < smallest_value)
                {
                    smallest_value = array[i];
                }
                
            }
            else{
                if (array[i+1] < smallest_value)
                {
                    smallest_value = array[i+1];
                }
                
            }
            
        }
        
    }
    return smallest_value;
    
}

template <typename T1, typename T2>
void print_telemetry(std::string label1, std::string label2, T1 paramter1, T2 parameter2){
    std::cout << label1 << ": " << paramter1 << " | " << label2 << ": " << parameter2 << std::endl;
}

template <typename T, const int size>
void print_sensor_frame2(T(&array)[size]){
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
}

int main(void){
    int a = 5;
    int b = 6;
    swap_parameters(a, b);

    const int myArray_size = 5;
    int myArray[myArray_size] = {6, 7, 3, 4, 5};
    print_sensor_frame(myArray);

    std::cout << "Smallest frame value: " << return_smallest_value(myArray) << std::endl;

    print_telemetry("Channel", "Priority", "motor_temp", 2);


}
