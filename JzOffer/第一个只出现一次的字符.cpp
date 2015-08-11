#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int len = str.size();
		if (len == 0)
			return -1;
		int times[256] = {0};
		for (int i = 0; i < len; i++)
			times[str[i]]++;
		for (int i = 0; i < len; i++)
			if (times[str[i]] == 1)
				return i;
		return -1;
	}


};