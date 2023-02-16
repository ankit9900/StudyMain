// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

using namespace std;

class Item
{
    protected:
    string name;
    int power;
    public:
    Item() {}
    virtual string getname()= 0;
    virtual int getPower() = 0;
};
class Weapon1 : public Item
{
    public:
    Weapon1(string s, int p) {name  = s; power = p;}
    string  getname() {return name;}
    int getPower() { return power; }
};
class weapon2 : public Item
{
    public:
    weapon2(string s, int p) {name  = s; power = p;}
    string getname() {return name;}
    int getPower() { return power; }
};

class magic : public Item
{
    Item* i;
    public:
    magic(Item* ii, string s, int po) {i = ii;  name = s ; power = po;}
    string  getname() {  return i->getname() + name; }
    int getPower() { return i->getPower() + power; }
};
int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    Item* m = new magic(new weapon2("wp2",10), "magix" , 300 );
    cout<< m->getname();
    cout<<m->getPower();
    return 0;
}
