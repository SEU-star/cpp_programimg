#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
	cout<<"Please enter the number of lines:";
	int n;
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
			cout<<setw(2)<<" ";
		for(k=i;k>=1;k--)
			cout<<setw(2)<<k;
		for(k=2;k<=i;k++)
			cout<<setw(2)<<k;
		cout<<"\n";
	}
	system("pause");
	return 0;
}