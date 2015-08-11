#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int k) {
		int len = str.size();
		if (k == len || k == 0 || len == 0)
			return str;
		k = k % len;
		reverse(str, 0, k - 1);
		reverse(str, k, len - 1);
		reverse(str, 0, len - 1);
		return str;
	}

	void reverse(string& s, int start, int end)
	{
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