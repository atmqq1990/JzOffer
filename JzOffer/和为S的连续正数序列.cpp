#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> res;
		if (sum < 3)
			return res;
		int end = sum / 2;
		int i = 1;
		int j = 2;
		int currentsum = i + j;
		while (i <= end)
		{
			while (currentsum < sum)
			{
				j++;
				currentsum += j;
			}

			while (currentsum >= sum && j - i >= 1)
			{
				if (currentsum == sum)
				{
					vector<int> vec;
					for (int k = i; k <= j; k++)
						vec.push_back(k);
					res.push_back(vec);

				}
				currentsum -= i;
				i++;
			}
		}

		return res;
	}
};