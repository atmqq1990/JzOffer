#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int len = array.size();
		if (len <= 1)
			return;
		vector<int> temp;
		for (int i = 0; i < len; i++)
			if ((array[i] & 1) == 1)
				temp.push_back(array[i]);
		for (int i = 0; i < len; i++)
			if ((array[i] & 1) == 0)
				temp.push_back(array[i]);
		array.clear();
		array.assign(temp.begin(),temp.end());
	}

};