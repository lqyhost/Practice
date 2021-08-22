#include <iostream>

template <bool Check, std::enable_if_t<Check>* = nullptr>
auto fun()
{
    return (int)0;
}

template <bool Check, std::enable_if_t<!Check>* = nullptr>
auto fun()
{
    return (double)1;
}

template <bool Check>
auto wrap2()
{
    return fun<Check>();
}

int main()
{
    std::cerr <<"true:"<< wrap2<true>() <<std::endl;
    std::cerr <<"false:"<< wrap2<false>() <<std::endl;
    return 0;
}