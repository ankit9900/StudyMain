// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

using namespace std;

//Product
//ProductBuilder
//DirctorOfproductBuilder

class Product
{
    string dough;
    string tomato;
    string onion;
    public:
    void taste()
    {
        cout<<"making Product using dough "<<dough << " tomatoes type "<< tomato<<" onion types "<<onion<<endl; 
    }
    void setD(string s) {dough = s;}
    void setT(string s) {tomato = s;}
    void setO(string s) {onion = s;}
};

class ProductBuilderInterface
{
    Product* p;
    public:
       void  create() { p = new Product;}
       Product* get() { return p;}
       virtual void setD() = 0;
       virtual void setT() = 0;
       virtual void setO() = 0;
       
};

class margarita : public ProductBuilderInterface
{
   public: 
   void  setD() { get()->setD("abc"); }
   void setT() { get()->setT("abc1"); }
   void setO() { get()->setO("abc2"); }
   
};

class farmhouse : public ProductBuilderInterface
{
   public:
   void setD() { get()->setD("xys"); }
   void setT() { get()->setT("xys1"); }
   void setO() { get()->setO("xys2"); }
};


class DirctorOfproductBuilder
{
   ProductBuilderInterface* pp; 
   public:
   void taste() { pp->get()->taste(); }
   void makePizza(ProductBuilderInterface* ppp)
   {
       pp = ppp;
       pp->create();
       pp->setD();
       pp->setT();
       pp->setO();
   }
};


int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    ProductBuilderInterface* p = new farmhouse();
    DirctorOfproductBuilder* d = new DirctorOfproductBuilder();
    d->makePizza(p);
    d->taste();
    
    
    return 0;
}
