#include <iostream>
using namespace std;

class vehicle
{
    public:
    static vehicle* get(int x);
    virtual void foo() {}
};
class one: public vehicle
{
    public:
    one() {cout<<"one"<<endl;}
     void foo() {cout<<"oneee "<<endl;}
};
class two: public vehicle
{
    public:
    two() {cout<<"two"<<endl;}
    void foo() {cout<<"twooo "<<endl;}
};

class third: public vehicle
{
    public:
    third() {cout<<"third"<<endl;}
    void foo() {cout<<"thirdddd "<<endl;}
};
 vehicle* vehicle::get(int x)
{
    if(x == 1) {
        return new one;
    }
    else if ( x == 2)
    {
        return new two;
    }
    else if(x == 3)
    {
        return new third;
    }
    else 
    {
        return nullptr;
    }
};
class client
{
    vehicle* v;
    public:
    client(int x) 
    {
        v = vehicle::get(x);
        if(v == nullptr)
        {
            cout<<"invalid object"<<endl;
        }
    }
    ~client()
    {delete v;}
    void foo()
    {
        if(v)
        v->foo();
        else 
        cout<<"No vehicle objet"<<endl;
    }
    
};
int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    client c(2);
    c.foo();
    return 0;
}
