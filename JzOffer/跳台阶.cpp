#include<iostream>
using namespace std;

class Solution {
public:
	int jumpFloor(int number) {
		if (number <= 1)
			return 1;
		else return jumpFloor(number - 1) + jumpFloor(number - 2);

	}
};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.jumpFloor(4);
	cout << res << endl;

	system("pause");
	return 0;
}
*/