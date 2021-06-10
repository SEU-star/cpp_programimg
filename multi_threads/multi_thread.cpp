#include <thread>
#include <iostream>
#include <unistd.h>
using namespace std;

void func()
{
    for (int i = 0; i < 100; ++i) 
    {
        std::cout<<"thread::func"<<std::endl;
    }
}
int main() 
{
    std::thread my_thread(func);
//    sleep(1);
    my_thread.detach();
    my_thread.join();
    return 0;
}

