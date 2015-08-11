#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index == 1)
			return 1;
		int *uglynumber = new int[index+1];
		uglynumber[0] = 0;
		uglynumber[1] = 1;
		int index2 = 1;
		int index3 = 1;
		int index5 = 1;
		int count = 1;
		while (count < index)
		{
			int minvalue = min(uglynumber[index2]*2,min(uglynumber[index3]*3, uglynumber[index5]*5));
			count++;
			uglynumber[count] = minvalue;
			while (uglynumber[index2] * 2 <= minvalue)
				index2++;
			while (uglynumber[index3] * 3 <= minvalue)
				index3++;
			while (uglynumber[index5] * 5 <= minvalue)
				index5++;
		}
		int res = uglynumber[index];
		delete[] uglynumber;
		return res;
		
	}

};