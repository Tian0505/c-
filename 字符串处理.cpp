#include <iostream>
#include<string>
using namespace std;
string performOperation(string s, char op, int n)
{
	if (op == 'L')
	{
		string newS = "";
		for (char c : s)
		{
			newS += c;
		 	newS += c;   
		}
		return newS;
	}
	else if (op == 'R')
	{
		string newS = s;
		for (int i = 0; i < s.length() / 2; ++i)
		{
			swap(newS[i], newS[s.length() - 1 - i]);
		}
		return newS;
	}
	else if (op == 'D')
	{
		int mid = s.length() / 2;
		if (n > s.length())
		{
			return "";
		}
		else
		{
			return s.substr(mid - n);
		}
	}
	return s;
} 
int main()
{
	string s;
	getline(cin, s);
	string line;
	while (true)
	{
		getline(cin, line);
		if (line == "End")
		{
			break;
		}
		int spacePos = line.find(' ');
		string operations = line.substr(0, spacePos);
		int k = stoi(line.substr(spacePos + 1));
		string tempS = s;
		for (char op : operations)
		{
			int num = 0;
			if (op == 'D')
			{
				int i = 1;
				while (isdigit(operations[i]))
				{
					num = num * 10 + (operations[i] - '0');
					i++;
				}
			}
			tempS = performOperation(tempS, op, num);
		}
		if (k > tempS.length())
		{
			cout << "NULL" << endl;
		}
		else
		{
			cout << tempS[k - 1] << endl;
		}
	}
	return 0;
}