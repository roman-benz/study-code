#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

template <typename T>
void analyze_vector(std::vector<T> &vector){
    auto it = std::max_element(vector.begin(), vector.end());
    if (it != vector.end())
    {
        std::cout << "Max value: " << *it << std::endl;

    }
    double average = static_cast<double>(std::accumulate(vector.begin(), vector.end(), 0)) / vector.size();
    std::cout << "Avg: " << average << std::endl;

    T sum = std::accumulate(vector.begin(), vector.end(), 0);
    std::cout << "Summe: " << sum << std::endl;
    
}

int main(void){
    std::vector<int> meinVector = {1, 2, 3, 4, 5};
    analyze_vector(meinVector);
}