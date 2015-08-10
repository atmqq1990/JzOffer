#include<iostream>
using namespace std;

class Solution {
public:
	int rectCover(int number) {
		if (number <= 1)
			return 1;
		int *re = new int[number + 1];
		re[0] = 1;
		re[1] = 1;
		re[2] = 2;
		for (int i = 2; i <= number; i++)
			re[i] = re[i - 1] + re[i - 2];
		int res = re[number];
		delete[] re;
		return res;
	}
};