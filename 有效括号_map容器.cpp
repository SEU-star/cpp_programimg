#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;


bool isVaild(string s)
{
	unordered_map<char, int> map;
	stack<char> st;
	map['(']= 1;map['[']=2;map['{']=3;map[')']=4;map[']']=5;map['}']=6;

	for(int i = 0;s[i];i++)
	{
		if(map[s[i]] <= 3 && map[s[i]] >= 1)
			st.push(s[i]);
		else if(st.empty() || (map[st.top()] != map[s[i]]-3))
			return false;
		else
			st.pop();
	}
	return st.empty();
}

int main()
{
	string s = "[]";
	isVaild(s);
	return 0;
}