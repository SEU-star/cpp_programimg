#include<thread>
#include<iostream>
#include<atomic>
using namespace std;

const int N=1e6;
atomic<int> n(0);

void increase_n()
{
    for(int i=0;i<N;i++)
    {
        ++n;
    }
}

int main()
{
    thread t1(increase_n);

    t1.detach();

    cout<<n<<endl;
    return 0;
}

