#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		*num1 = 0;
		*num2 = 0;
		int len = data.size();
		if (len < 2)
			return;
		int xorvalue = 0;
		for (int i = 0; i<len; i++)
			xorvalue ^= data[i];

		int factor = lowestnonzerovalue(xorvalue);
		for (int i = 0; i<len; i++)
			if ((data[i] & factor) != 0)
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
	}

	int lowestnonzerovalue(int value)
	{
		int factor = 1;
		while ((value & factor) == 0)
			factor = factor << 1;
		return factor;
	}
};