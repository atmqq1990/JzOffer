#include<iostream>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
		if (n < 1)
			return 0;
		if (n < 9)
			return 1;
		int count = 0;
		int left = 0;
		int right = 0;
		int currentdigit = 0;
		long long factor = 1;
		int temp = 0;
		while (factor <= n)
		{
			right = n % factor;
			temp = n / factor;
			left = temp / 10;
			currentdigit = temp % 10;
			if (currentdigit == 0)
				count += left * factor;
			else if (currentdigit == 1)
				count += left*factor + right + 1;
			else if (currentdigit > 1)
				count += (left + 1)*factor;
			factor *= 10;
		}

		return count;
    }

};