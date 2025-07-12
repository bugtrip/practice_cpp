#include <iostream>
#include <vector>

template<typename T, typename F>
void check_value(T x, std::vector<T>& arr, F filter){
    for(auto it = arr.begin(); it != arr.end();){
        if(filter(x, *it)){
            arr.erase(it);
        } else {
            ++it;
        }
    }
    arr.shrink_to_fit();
}

template<typename T>
void print_vector(std::vector<T>& v){
    if(v.empty()){ 
        std::cout << "vector is empty!" << std::endl; 
    } else {
        for(auto& elem: v){
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    std::vector<int> v1{635, 15, 1243, 4967, 6523, 15, 41, 6213, 86, 0, 15, 15, 432, 78, 15, 4375, 43, 69, 8};
    print_vector(v1);
    int var1{15};
    check_value<int>(var1, v1, [](auto x, auto elem)->bool{ return x == elem; });
    print_vector(v1);

    std::vector<double> v2{87.23, 71.12, 914.71, 534.3, 5634.13, 3246.11, 831.63, 89.41, 41.75, 5634.14, 5634.13, 6334.1};
    print_vector(v2);
    double var2{5634.13};
    check_value<double>(var2, v2, [](auto x, auto elem)->bool{ return x == elem; });
    print_vector(v2);

    std::vector<short> v3{54, 124, 85, 764, 87, 9, 1, 53, 85, 12, 734, 123, 85, 63, 12, 4, 112, 85, 854, 42, 143, 4, 4, 3, 32, 1};
    print_vector(v3);
    short var3{85};
    check_value<short>(var3, v3, [](auto x, auto elem)->bool{ return x == elem; });
    print_vector(v3);

    return 0;
}
