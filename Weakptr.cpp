/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory>
#include <string>

using namespace std;
class test 
{
    string name;
    //shared_ptr<test> p;
    weak_ptr<test> p;
    public:
    test(string s)
    {
        name = s;
    }
    friend void partner(shared_ptr<test>&  t1, shared_ptr<test>& t2)
    {
        t1->p=t2;
        t2->p = t1;
    }
    ~test()
    {
        cout<<"DTR "<<endl;
    }
    const shared_ptr<test> getPartner() 
    {
          return p.lock();
    }
    const string& namef()
    {
      return name;
    }
    
};
int main()
{
    //cout<<"Hello World";
    auto sp1 = make_shared<test>("abc");
    auto sp2 = make_shared<test>("xys");
    
     partner(sp1, sp2);
     auto pp = sp1->getPartner();
     cout<<pp->namef();
    return 0;
}

