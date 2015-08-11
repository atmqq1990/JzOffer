#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> res;
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int size = input.size();
		if (size == 0)
			return res;
		if (k > size || k <= 0)
			return res;
		findK(input,0,size-1,k);
		sort(res.begin(),res.end());
		return res;
	}

	void findK(vector<int>& input, int start, int end, int k)
	{
		int len = end - start + 1;
		if (k == 1)
		{
			int minvalue = input[start];
			for (int i = start + 1; i <= end; i++)
				if (input[i] < minvalue)
					minvalue = input[i];
			res.push_back(minvalue);
		}
		else if (k == len)
		{
			for (int i = start; i <= end; i++)
				res.push_back(input[i]);
		}
		else
		{
			int index = partition(input,start,end);
			if (index == k - 1)
			{
				for (int i = 0; i <= index; i++)
					res.push_back(input[start+i]);
			}
			else if (index < k - 1)
			{
				for (int i = 0; i <= index; i++)
					res.push_back(input[start + i]);
				findK(input,start+index+1,end,k-index-1);
			}
			else if (index == k)
			{
				for (int i = 0; i < index; i++)
					res.push_back(input[start + i]);
			}
			else if (index > k)
			{
				findK(input,start,index-1,k);
			}

		}
		
	}

	int partition(vector<int>&input, int start, int end)
	{
		int piovt = input[start];
		int i = start, j = end;
		while (i < j)
		{
			while (i < j && input[j] >= piovt)
				j--;
			if (i < j)
			{
				input[i] = input[j];
				i++;
			}
			while (i < j && input[i] <= piovt)
				i++;
			if (i < j)
			{
				input[j] = input[i];
				j--;
			}
		}
		input[i] = piovt;
		return i - start;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = { 4,5,1,6,2,7,3,8 };
	vector<int> res = so.GetLeastNumbers_Solution(v,8);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
*/