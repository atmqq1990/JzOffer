#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int maxsum = INT_MIN;
		int currentsum = 0;
		int len = array.size();
		if (len == 0)
			return 0;
		for (int i = 0; i < len; i++)
		{
			currentsum += array[i];
			if (currentsum > maxsum)
				maxsum = currentsum;
			if (currentsum < 0)
				currentsum = 0;
		}
		return maxsum;
	}

};

