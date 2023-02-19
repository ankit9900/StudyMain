// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

class Car
{
    
    string color;
    int model;
    
    public:
    Car(const string& co, int mo) : color(co), model(mo) {}
    virtual Car* clone() = 0;
     void setColor(const string& s) {color = s;}
     void setModel(int year) {model = year;} 
      string getColor() {return color;}
     int getModel() {return model ;} 
    virtual void print() = 0;
};
class Car1 : public Car
{
    int speed;
    public:
    Car1(const string & co, int mo, int spe):Car(co, mo), speed(spe){}
    Car1* clone() {return new Car1(*this); }
    void print() {
        cout<<getColor() <<" "<<getModel() <<" "<<speed<<endl;
    }
    
};

int main() {
    // Write C++ code here
    std::cout << "Hello world!";
   Car* pro = new Car1("", 1998, 200);
   
   Car* blue = pro->clone();
   blue->setColor("blue");
    Car* red = pro->clone();
   red->setColor("red");
   
   blue->print();
   red->print();
   
    return 0;
}
