#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int len = A.size();
		if (len == 0)
		{
			return vector<int>();
		}

		vector<int> vec(len, 1);
		int temp = A[0];
		for (int i = 1; i<len; i++)
		{
			vec[i] *= temp;
			temp *= A[i];
		}

		temp = A[len - 1];
		for (int i = len - 2; i >= 0; i--)
		{
			vec[i] *= temp;
			temp *= A[i];
		}

		return vec;
	}
};