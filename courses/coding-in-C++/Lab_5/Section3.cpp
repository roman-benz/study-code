#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

// template <typename T>
// void analyze_vector(std::vector<T> &vector){
//     auto it = std::max_element(vector.begin(), vector.end());
//     if (it != vector.end())
//     {
//         std::cout << "Max value: " << *it << std::endl;

//     }
//     double average = static_cast<double>(std::accumulate(vector.begin(), vector.end(), 0)) / vector.size();
//     std::cout << "Avg: " << average << std::endl;

//     T sum = std::accumulate(vector.begin(), vector.end(), 0);
//     std::cout << "Summe: " << sum << std::endl;
    
// }
constexpr int SENSORFRAME_SIZE = 10;
template <typename T>
void transfer_data(T* array, std::vector<T> &vector){
    for (int i = 0; i < SENSORFRAME_SIZE; i++)
    {
        vector.push_back(array[i]);
    }
    analyze_vector(vector);
}

template <typename T>
T analyze_vector(std::vector<T> &vector){
    if (!std::is_same_v<T, bool>)
    {
        auto it = std::max_element(vector.begin(), vector.end());
        if (it != vector.end())
        {
            std::cout << "Max value: " << *it << std::endl;

        }
        double average = static_cast<double>(std::accumulate(vector.begin(), vector.end(), 0)) / vector.size();
        std::cout << "Avg: " << average << std::endl;

        T sum = std::accumulate(vector.begin(), vector.end(), 0);
        std::cout << "Summe: " << sum << std::endl;
        return NULL;
    }
    else{
        int true_count = 0;
        for (bool data : vector){
            if (data == true)
            {
                true_count++;
            }
                        
        }
        if (true_count >= (vector.size()/2))
        {
            std::cout << "Motor was active for the majority of the time" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Motor was inactive for the majority of the time" << std::endl;
            return false;
        }
        
        
    }
    
    
    
}

int main(void){
    std::vector<int> meinVector = {1, 2, 3, 4, 5};
    analyze_vector(meinVector);
}