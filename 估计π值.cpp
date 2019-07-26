#include<iostream>
#include<ctime>
#include<iomanip>
#include<cstdlib>
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
		if(x*x+y*y<=1)
			numberofhits++;
	}
	double pi=4.0*numberofhits/Numberofhits;
	cout<<"PI is :"<<setprecision(3)<<pi<<endl;
	system("pause");
	return 0;
}