#include<iostream>
using namespace std;

class Solution {
public:
	int jumpFloorII(int number) {

		if (number == 1)
			return 1;
		else
			return 1 << (number - 1);

	}
};