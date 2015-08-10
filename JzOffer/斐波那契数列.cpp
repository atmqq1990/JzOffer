#include<iostream>
using namespace std;

class Solution {
public:
	int Fibonacci(int n) {
		if (n < 2)
			return n;
		int *fb = new int[n + 1];
		fb[0] = 0;
		fb[1] = 1;
		for (int i = 2; i <= n; i++)
			fb[i] = fb[i - 1] + fb[i - 2];
		int res = fb[n];
		delete[] fb;
		return res;
	}
};