#include<iostream>
using namespace std;
int main ()
{
	cout<<"Please enter two integers";
	int integer1,integer2,gcd;
	while(1)
	{
	cin>>integer1>>integer2;
	if(integer1>=integer2)
		gcd=integer2;
	else
		gcd=integer1;
	do
	{
		if((0==integer1%gcd)&&(0==integer2%gcd))
		{
		cout<<"The gcd is:"<<gcd<<endl;
		break;
		}
		else
			gcd--;
	}while(1)
		break;
	system("pause");
	return 0;
}