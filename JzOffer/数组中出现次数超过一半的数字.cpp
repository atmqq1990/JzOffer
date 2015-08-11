#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int value = -1;
		int count = 0;
		int len = numbers.size();
		for (int i = 0; i < len; i++)
		{
			if (count == 0)
			{
				count = 1;
				value = numbers[i];
			}
			else if (numbers[i] == value)
			{
				count++;
			}
			else
				count--;
		}
		count = 0;
		for (int i = 0; i < len; i++)
			if (numbers[i] == value)
				count++;
		if(count > len/2)
			return value;
		return 0;
	}

};