// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class SI;
class OI
{
    public:
     virtual void notify() = 0;
     virtual  void register1(SI* s) = 0;
     virtual  void deregister1(SI* s) = 0;
};
class SI
{
     vector<OI*>v;
    public:
     virtual void  register1(OI* o) = 0;
     virtual void deregister1(OI* o) = 0;
     virtual  void notify() = 0;
     const vector<OI*>& get() const { return v ;}
     vector<OI*>& get() { return v ;}
     
};

class CSI1 : public SI
{
    public:
    void  register1(OI* o)
     {
         get().push_back(o);
     }
     void deregister1(OI* o) 
     {
          auto i = find(get().begin(), get().end(), o);
          if(i != get().end())
          {
              get().erase(i);
          }
     }
     void notify()
     {
         for(const auto& a : get())
         {
             a->notify();
         }
     }
     void foo() {cout<<"CSI1 "<<endl;}
};

class O1 : public OI
{
    public:
    O1() {cout<<"O1" <<endl;}
    void notify() {cout<<"O1 get the signal "<<endl;}
    void register1(SI* s) {s->register1(this);}
    void deregister1(SI* s) {s->deregister1(this);}
};
class O2 : public OI
{
     public:
    O2() {cout<<"O2" <<endl;}
    void notify() {cout<<"O2 get the signal "<<endl;}
     void register1(SI* s) {s->register1(this);}
     void deregister1(SI* s) {s->deregister1(this);}
};
class O3 : public OI
{
     public:
    O3() {cout<<"O3" <<endl;}
    void notify() {cout<<"O3 get the signal "<<endl;}
     void register1(SI* s) {s->register1(this);}
     void deregister1(SI* s) {s->deregister1(this);}
};



int main() {
    // Write C++ code here
    std::cout << "Hello world!";
     SI* s = new CSI1;
     OI* o = new O1();
     OI* oo = new O2();
     OI* xx = new O3();
     
    o->register1(s);
    oo->register1(s);
    xx->register1(s);
    s->notify();
     xx->deregister1(s);
     s->notify();
    
    return 0;
}
