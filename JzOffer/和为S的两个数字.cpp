#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> res;
		int len = array.size();
		if (len < 2)
			return res;
		int i = 0, j = len - 1;
		int a = INT_MIN, b = INT_MIN;
		while (i < j)
		{
			if (array[i] + array[j] == sum)
			{
				if (a == INT_MIN || array[i] * array[j] < a*b)
				{
					a = array[i];
					b = array[j];
				}
				i++;
			}
			else if (array[i] + array[j] < sum)
				i++;
			else if (array[i] + array[j] > sum)
				j--;
		}
		if (a != INT_MIN && b != INT_MIN)
		{
			res.push_back(a);
			res.push_back(b);
		}
		return res;
	}
};