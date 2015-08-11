#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		int len = str.size();
		int current = 0;
		bool neg = false;
		int i = 0;
		while (i < len && str[i] == ' ')
			i++;
		if (i == len)
			return current;
		if (str[i] == '-')
		{
			neg = true;
			i++;
		}
		else if (str[i] == '+')
			i++;
		while (i < len)
		{
			if (str[i]>'9' || str[i]<'0')
				return 0;
			current = current * 10 + str[i] - '0';
			i++;
		}
		if (neg)
			current = -current;
		return current;
	}
};