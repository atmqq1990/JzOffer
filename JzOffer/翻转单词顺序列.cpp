#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		int len = str.size();
		if (len <= 1)
			return str;
		int i = 0, j = 0;
		while (i < len)
		{
			while (j < len && str[j] != ' ')
				j++;
			j--;
			reverse(str, i, j);
			j++;
			while (j < len && str[j] == ' ')
				j++;
			i = j;
		}
		reverse(str, 0, len - 1);
		return str;
	}

	void reverse(string& s, int start, int end)
	{
		if (start >= end)
			return;
		char temp;
		int i = start, j = end;
		while (i < j)
		{
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
		}
	}
};