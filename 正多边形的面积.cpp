#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main ()
{
	const double PI=3.14159;
	double area;
	double numerator,denominator;
	cout<<"Please enter the number of sides";
	int sides;
	cin>>sides;
	cout<<"Please enter the length of side";
	double length;
	cin>>length;
	numerator=sides*pow(length,2);
	denominator=4*tan(PI/sides);
	area=numerator/denominator;
	cout<<"The area of the polygon is:"<<fixed<<setprecision(4)<<area<<endl;
	system("pause");
	return 0;
}