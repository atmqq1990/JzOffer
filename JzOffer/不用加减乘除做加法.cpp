#include<iostream>
using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		if (num1 == 0)
			return num2;
		if (num2 == 0)
			return num1;
		int xorvalue = num1 ^ num2;
		int jinwei = num1 & num2;
		while (jinwei != 0)
		{
			jinwei = jinwei << 1;
			int orginal = xorvalue;
			xorvalue = xorvalue ^ jinwei;
			jinwei = jinwei & orginal;
		}

		return xorvalue;
	}
};