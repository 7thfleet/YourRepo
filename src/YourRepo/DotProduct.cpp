#include "YourRepo/DotProduct.hpp"

#include <stdexcept>

int YourRepo::DotProduct(const std::vector<int>& a, const std::vector<int>& b){
    if(a.size() != b.size()){
        throw std::invalid_argument("vector a and b must have the same length");
    }

    int sum = 0;
    for(std::size_t i = 0; i < a.size(); ++i){
        sum += a.at(i) * b.at(i);
    }

    return sum;
}
