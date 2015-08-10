#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
	void push(int value) {
		valst.push(value);
		if (minst.empty())
			minst.push(value);
		else
			minst.push(std::min(value,minst.top()));
	}
	void pop() {
		valst.pop();
		minst.pop();
	}
	int top() {
		return valst.top();
	}
	int min() {
		return minst.top();
	}
private:
	stack<int> valst;
	stack<int> minst;

};