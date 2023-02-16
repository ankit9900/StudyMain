// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class I1
{
    public:
    virtual void foo() = 0;
};
class a : public  I1
{
    public:
    virtual void foo() {cout<<"A "<<endl;}
};
class b : public I1
{
    public:
    virtual void foo() {cout<<"B "<<endl;}
};

class I2
{
    public:
    virtual void foo() = 0;
};
class aa : public  I2
{
    public:
    virtual void foo() {cout<<"Aa "<<endl;}
};
class bb : public I2
{
    public:
    virtual void foo() {cout<<"Bb "<<endl;}
};

class Adapter : public I1
{
    I2* a;
    public:
    Adapter(I2* aa) {a = aa;}
    void foo(){a->foo();}
};
int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    I2* obj = new aa;
    Adapter a(obj);
    a.foo();
    return 0;
}
