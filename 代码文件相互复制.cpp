#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	while(1)
	{
	cout << "请输入源文件的路径：（例如：E:\\temp\\a.cpp）" << endl;
	string inputfilename;
	getline(cin, inputfilename);

	cout << "请输入目标文件的路径：(例如：E:\\temp\\b.cpp)  " << endl;
	string outputfilename;
	getline(cin, outputfilename);

	ifstream input(inputfilename.c_str());
	ofstream output(outputfilename.c_str());

	if( input.fail() )
	{
		cout << inputfilename << " 不存在 " << endl;
	}
	char ch = input.get();
	while( !input.eof() )
	{
		output.put(ch);
		ch = input.get();
	}

	input.close();
	output.close();

	cout << "复制完毕" << endl;
	}
	return 0;
}