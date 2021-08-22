#include <iostream>
using namespace::std;


//元函数等级划分
//进行基本变换，比如输入类型返回指针的元函数
//包含了顺序、分支和循环逻辑的元函数
//奇特递归模版式元函数

//奇特递归模版式是一种派生类声明，派生类本身会作为模版参数传递给基类
//可以应用在比如函数无法声明为虚函数

template <typename D>
struct Base
{
    template <typename TI>
    void Func(const TI& input)
    {
        D* ptr = static_cast<D*>(this);
        ptr->Imp(input);//这里的imp就是奇特地柜模版式元函数,模版函数无法声明为虚函数，所以可以借助奇特递归模版式实现
    }
    static void Func1()
    {
        D::Imp1();//同理，静态函数无法声明为虚函数，也可以使用
    }    
};

struct Derive: public Base<Derive>
{
    template<typename TI>
    void Imp(const TI& input)//模版函数无法声明为虚函数，所以可以借助奇特递归模版式实现
    {
        cout<<input<<endl;
    }
    static void Imp1()
    {
        cout<<"Imp1"<<endl;
    }
};

int main()
{
    Derive d;
    d.Func("sdfasdfasdsrew serfwer");
    d.Func1();
}
