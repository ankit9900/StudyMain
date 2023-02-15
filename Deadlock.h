class test1
{
    thread t1;
    thread t2;
    mutex m1;
    mutex m2;
    public:
    test1()
     {
         t1 = thread (&test1::one, this);
         t2 = thread (&test1::two, this);
         t1.join();
         t2.join();
     }
    void one()
    {
        {
        lock_guard<mutex> lock1(m1);
        lock_guard<mutex> lock2(m2);
        cout<<"Thread 1 "<< endl;
        }
    }
    void two()
    {
        {
        lock_guard<mutex> lock1(m2);
        sleep(1000);
        lock_guard<mutex> lock2(m1);
        cout<<"Thread 2 "<< endl;
        }
    }
};
