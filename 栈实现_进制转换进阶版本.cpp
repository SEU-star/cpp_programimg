#include<iostream>
#include<string>
#include<stack>
using namespace std;


void convert(stack<char>& s, int n, int base)
{
	static char digit[] = {'0','1' ,'2', '3','4','5','6','7','8','9','A','B','C','D','E','F'};
	while(n > 0)
	{
		int remain = (int)(n % base);
		s.push(digit[remain]);
		n = n / base;
	}
	while (!s.empty())
	{
		cout << " " << s.top();
		s.pop();
	}
}

int main()
{
	cout << "请输入将要转换的整数："<< endl;
	int num;
	cin >> num;

	cout << "请输入将要转换的目标进制：" << endl;
	int n;
	cin >> n;
	stack<char> s;

	convert(s, num, n);
	return 0;
}