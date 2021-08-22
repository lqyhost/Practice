#include <iostream>

template<size_t Input>
constexpr size_t OnesCount = (Input %2) + OnesCount<(Input /2)>;

template<>
constexpr size_t OnesCount<0> = 0;

int main()
{
    std::cout<<"size 55 "<<OnesCount<55><<std::endl;
    //std::cout<<"fun<false>()"<<fun<false>()<<std::endl;
}