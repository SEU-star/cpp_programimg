#include<iostream>
#include<ctime>
using namespace std;
int main ()
{
	int numberofhits=0;
	const int Numberofhits=1000000;
	srand(time(0));
	for(int i=0;i<Numberofhits;i++)
	{
		double x=rand()*2.0/RAND_MAX-1;
		double y=rand()*2.0/RAND_MAX-1;
		if(x*x+y*y<1)
			numberofhits++;
	}
	double pi=4*numberofhits/Numberofhits;
	cout<<"PI is :"<<pi<<endl;
	system("pause");
	return 0;
}