// Online C++ compiler to run C++ program online
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;
class test
{
    thread t1;
    thread t2;
    mutex m;
    condition_variable cv;
    int i;
    int N;
    public:
    
    void odd()
    {
        while( i < N) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [&] {return i%2 != 0;}) ;
        cout<<"Odd "<<i<<endl;
        ++i;
        ul.unlock();
        cv.notify_one();
        }
    }
    void even()
    {
        while( i < N) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [&]{return i%2 == 0;}) ;
        cout<<" even " <<i<<endl;
        ++i;
        ul.unlock();
         cv.notify_one();
       }
    }
    test()
    {
        i = 1;
        N = 100;
        t1 = thread(&test::odd, this);
        t2= thread(&test::even,this);
        t1.join();
        t2.join();
    }
};
int main() {
    // Write C++ code here
    std::cout << "Hello world!";
     test ww;
    return 0;
}
