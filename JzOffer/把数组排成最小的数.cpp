#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	static bool cmp(string a, string b)
	{
		return a + b < b + a;
	}

	string PrintMinNumber(vector<int> numbers) {
		vector<string> words;
		int len = numbers.size();
		for (int i = 0; i < len; i++)
			words.push_back(inttostring(numbers[i]));
		sort(words.begin(),words.end(),cmp);
		string res;
		for (int i = 0; i < len; i++)
			res.append(words[i]);
		return res;
	}

	string inttostring(int a)
	{
		if (a == 0)
			return "0";
		stack<char> st;
		int yu = 0;
		while (a != 0)
		{
			yu = a % 10;
			a = a / 10;
			st.push(yu+'0');
		}
		string res;
		while (!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}
		return res;
	}


};