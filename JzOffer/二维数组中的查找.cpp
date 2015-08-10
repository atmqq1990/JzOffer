#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool Find(vector<vector<int> > array, int target) {
		int m = array.size();
		int n = array[0].size();
		int i = 0, j = n - 1;
		while (i < m && j >= 0)
		{
			if (array[i][j] == target)
				return true;
			else if (array[i][j] > target)
				j--;
			else if (array[i][j] < target)
				i++;
		}

		return false;

	}
};