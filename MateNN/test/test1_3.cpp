#include <iostream>

template <bool Check>
auto fun()
{
    if constexpr(Check)
        return (int)1;
    else
        return (double)0;
}

int main()
{
    std::cout<<"fun<true>()"<<fun<true>()<<std::endl;
    std::cout<<"fun<false>()"<<fun<false>()<<std::endl;
}