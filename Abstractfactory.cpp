// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class widget
{
   public:
      virtual void draw() = 0;
      
};
class button1 : public  widget
{
     public:
     virtual void draw()  {
      cout<<"Base widget b1 "<<endl;
     }
};
class button2 : public  widget
{
     public:
      virtual void draw()  {
      cout<<"Base widget b2 "<<endl;
     }
};
class button3 : public  widget
{
     public:
      virtual void draw()  {
      cout<<"Base widget b3 "<<endl;
     }
};
class AbstractFactory1
{ 
    protected:
     widget* w1;
    widget* w2;
    public:
    virtual void draw() = 0;
    
};
class CF11 : public AbstractFactory1
{
   
    public:
    CF11()
    {
         w1 = new button1;
         w2 = new button2;
    }
    void draw()
    {
        w1->draw();
        w2->draw();
    }
    
};
class CF12 : public AbstractFactory1
{
    
    public:
    CF12()
    {
         w1 = new button2;
         w2 = new button3;
    }
    void draw()
    {
        w1->draw();
        w2->draw();
    }
};
class CF13 : public AbstractFactory1
{
   
    public:
    CF13()
    {
         w1 = new button1;
         w2 = new button3;
    }
    void draw()
    {
        w1->draw();
        w2->draw();
    }
};

class Client
{
    AbstractFactory1* af;
    public:
    Client(int x)
    {
        if(x == 1)
        {
            af = new CF11;
        }
         if(x == 2)
        {
            af = new CF12;
        }
         if(x == 3)
        {
            af = new CF13;
        }
    }
    void draw()
    {
        af->draw();
    }
    
};


int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    Client c(2);
    c.draw();
    return 0;
}
