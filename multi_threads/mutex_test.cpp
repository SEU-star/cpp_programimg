#include <thread>
#include <iostream>
#include <mutex>
#include <unistd.h>
using namespace std;

mutex m;
const int N=10000;
int n;

void increase_n()
{
    for(int i=0;i<N;i++)
    {
        m.lock();
        ++n;
        m.unlock();
    }
}

int main()
{
    thread t1(increase_n);
    t1.detach();
//    sleep(1);
    n++;
    cout<<n<<endl;
    return 0;
}

