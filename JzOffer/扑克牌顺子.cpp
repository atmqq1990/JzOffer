#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		int len = numbers.size();
		if (len == 0)
			return false;
		if (len == 1)
			return true;
		sort(numbers.begin(), numbers.end());
		int zerocount = 0;
		int i = 0;
		int needed = 0;
		while (i<len && numbers[i] == 0)
		{
			zerocount++;
			i++;
		}
		i++;
		while (i< len)
		{
			if (numbers[i] == numbers[i - 1])
				return false;
			needed += numbers[i] - numbers[i - 1] - 1;
			i++;
		}

		return zerocount >= needed;
	}
};