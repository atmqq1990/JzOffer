#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		int len = num.size();
		if (len == 0)
			return res;
		if (size == 0)
			return res;
		if (size == 1)
			return num;
		deque<int> dq;
		if (len < size)
			return res;
		int i = 0;
		while (i < size)
		{
			if (dq.empty())
				dq.push_front(i);
			else if (num[i] >= num[dq.front()])
			{
				while (!dq.empty() && num[i] >= num[dq.front()])
					dq.pop_front();
				dq.push_front(i);
			}
			else 
			{
				while (!dq.empty() && num[i] >= num[dq.back()])
					dq.pop_back();
				dq.push_back(i);
			}
			i++;
		}
		res.push_back(num[dq.front()]);
		while (i < len)
		{
			if (dq.front() == i - size)
				dq.pop_front();
			if (dq.empty())
				dq.push_front(i);
			else if (num[i] >= num[dq.front()])
			{
				while (!dq.empty() && num[i] >= num[dq.front()])
					dq.pop_front();
				dq.push_front(i);
			}
			else 
			{
				while (!dq.empty() && num[i] >= num[dq.back()])
					dq.pop_back();
				dq.push_back(i);
			}
			res.push_back(num[dq.front()]);
			i++;
		}

		return res;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = { 16,14,12,10,8,6,4 };
	vector<int> res = so.maxInWindows(v,5);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/