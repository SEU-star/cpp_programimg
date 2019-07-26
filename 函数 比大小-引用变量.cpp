#include<iostream>
#include<iomanip>
using namespace std;

void printMonth(int year,int month);
void printMonthTitle(int year,int month);
void printMonthBody(int year,int month);
void printMonthName(int month);
int getStartDay(int year,int month);
int getTotalDaysOfMonth(int year,int month);
int getTotalDays(int year,int month);
int main()
{
	cout<<"please enter the year you want to know(after 1800):";
	int year;
	cin>>year;
	cout<<"please enter the month you want to know:";
	int month;
	cin>>month;
	if(month<=0&&month>12)
	{
		cout<<"the month is illegal,and please enter a month again:";
		cin>>month;
	}
	printMonth(int year,int month);
	system("pause");
	return 0;
}
void printMonth(int year,int month)
{
	printMonthTitle(int year,int month);
	printMOnthBody(int year,int month£©;
}
void printMonthTitle(int year,int month)
{
	printMonthName(int month);
	cout<<" "<<year<<endl;
	cout<<"----------------------------"<<endl;
	cout<<"Sun Mon Tue Wed Thu Fri Sat"<<endl;
}
void printMonthName(int month)
{
	switch (month)
	{
	case 1:
		cout<<"January";
		break;
	case 2:
		cout<<"February";
		break;
	case 3:
		cout<<"March";
		break;
	case 4:
		cout<<"April";
		break;
	case 5:
		cout<<"May";
		break;
	case 6:
		cout<<"June";
		break;
	case 7:
		cout<<"July";
		break;
	case 8:
		cout<<"August";
		break;
	case 9:
		cout<<"September";
		break;
	case 10:
		cout<<"October";
		break;
	case 11:
		cout<<"November";
		break;
	case 12:
		cout<<"December";
		break;
	}
}
void printMonthBody(int year,int month)
{
	int StartDay=getStartDay(year,month);
	int TotalDaysOfMonth=getTotalDaysOfMonth(year,month);
	for(i=0;i<StartDay;i++)
		cout<<" ";
	for(i=1;i<=TotalDaysOfMonth;i++)
	{
		cout<<setw(4)<<i;
		if((i+StartDay)%7==0)
			cout<<endl;
	}
}
int getStartDay(int year,int month)
{
	int TotalDays=getTotalDays(int year,int month);
	StartDay=(TotalDays+3)%7;
	return StartDay;
}
int getTotalDays(int year,int month)
{
	for(i=1800;i<year:i++)
	{
		TotalDays=0;
		if(year%400==0||(year%4==0&&year%100==0))
			TotalDays=TotalDays+365;
		else
			TotalDays=TotalDays+366;
	}
	for(i=1;i<month;i++)
	{
		int MonthDays=getTotalDaysOfMonth(int year,int month);
		TotalDays=TotalDays+MonthDays;
	}
	return TotalDays;
}
int getTotalDaysOfMonth(int year,int month)
{
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		TotalDaysOfMonth=31;
		return TotalDaysOfMonth;
	}
	if(month==4||month==6||month==9||month==11)
	{
		TotalDaysOfMonth=30;
		return TotalDaysOfMonth;
	}
	else
	{
		if(year%400==0||(year%4==0&&year%100==0))
			return 28;
		else
			return 29;
	}
}