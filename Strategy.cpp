// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Flyable
{
    public:
    virtual void fly() = 0;
};
class Animal
{
        Flyable* f;
    public:
        virtual void makesound() = 0;
        Flyable*& get() { return f; }
        virtual void set(Flyable* ff) = 0; 
        virtual void fly() = 0;
    
};
class Dog : public Animal
{
    public:
    void makesound() { cout<<"Bark"<<endl;}
    void fly() {get() -> fly() ;}
    void set(Flyable* ff) {
        get() = ff;
    }
};
class Duck : public Animal
{
    public:
    void makesound() { cout<<"Quack"<<endl;}
    void fly() {get() -> fly() ;}
    void set(Flyable* ff) {
          get() = ff;
    }
};


class canFly : public Flyable
{
    public:
    void fly() {cout<<"I can fly"<<endl;}
};
class canNotFly : public Flyable
{
    public:
    void fly() {cout<<"I can NOT fly"<<endl;}
};

int main() {
    // Write C++ code here
   // std::cout << "Hello world!";
    Animal* a = new Dog();
    Animal* b = new Duck();
    a->set(new canNotFly());
    b->set(new canFly());
    a->fly();
    b->fly();
    return 0;
}
