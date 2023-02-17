// Online C++ compiler to run C++ program online
#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <queue>
#include <condition_variable>
#include <unistd.h>
using namespace std;


int data1;
mutex m;
bool ready = false;
condition_variable cv;
int i = 0;
void Producer()
{
    while(1)
    {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [&]() { return ready == false;});
        data1 = i++;
        cout<<"Pro "<<data1<<endl;
        ready = true;
        lk.unlock();
        cv.notify_one();
    }
}

void  Consumer ()
{
    while(1)
    {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [&]() { return ready;});
        cout<<"consume "<<data1<<endl;
        ready = false;
        lk.unlock();
        cv.notify_one();
    }
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    thread t1(Producer);
    thread t2(Consumer);
    t1.join();
    t2.join();
    return 0;
}
