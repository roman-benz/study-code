#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
void print_flight_data(std::vector<T> &vector){
    for (T data : vector)
    {
        std::cout << data << " ";
    }
    std::cout << std::endl;
    
}

template <typename T>
void sort_data(std::vector<T> &vector){
    std::sort(vector.begin(), vector.end());
}

template <typename T>
void find_data(std::vector<T> &vector, T data){

    auto it = std::find(vector.begin(), vector.end(), data);

    if(it != vector.end()){
        std::cout << "Found data" << std::endl;
    }
    else{
        std::cout << "Data not found" << std::endl;

    }

}

template <typename T> 
void cleanup(std::vector<T> &v){
    std::cout << "Vector cleanup" << std::endl;

    std::replace(v.begin(), v.end(), -1, 0);
    print_flight_data(v);

    int count_8 = std::count(v.begin(), v.end(), 8);
    print_flight_data(v);
    
    std::reverse(v.begin(), v.end());
    print_flight_data(v);
    
};

template <typename T> 
void manual_iterator_walk(std::vector<T> &v){
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
};




int main(void){
    std::vector<int> v_flightdata = {42, 17, 42, 5, 99, 17, 63, 12};
    print_flight_data(v_flightdata);
    sort_data(v_flightdata);
    print_flight_data(v_flightdata);
    find_data(v_flightdata, 64);

    std::vector<int> faulty_data = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    cleanup(faulty_data);
    manual_iterator_walk(v_flightdata);
};