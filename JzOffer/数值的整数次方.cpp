#include<iostream>
using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
			return 1;
		long long exp = exponent;
		if (exp < 0)
			exp = -exp;
		double res = pow(base, exp);
		if (exponent > 0)
			return res;
		else
			return 1.0 / res;

	}

	//base positive, exp postive
	double pow(double base, long long exp)
	{
		if (exp == 0)
			return 1;
		double temp = pow(base, exp >> 1);
		temp *= temp;
		if (exp & 1 == 1)
			temp *= base;
		return temp;
	}
};