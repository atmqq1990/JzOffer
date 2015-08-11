#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int inversecount = 0;
	int InversePairs(vector<int> data) {
		int len = data.size();
		if (len < 2)
			return 0;
		inverse(data,0,len-1);
		return inversecount;
	}

	void inverse(vector<int>&data, int start, int end)
	{
		if (start == end)
			return;
		int mid = (start + end) / 2;
		inverse(data,start,mid);
		inverse(data,mid+1,end);
		int i = mid, j = end;
		while (i >= start && j >= mid + 1)
		{
			if (data[i] > data[j])
			{
				inversecount += j - mid;
				i--;
			}
			else if (data[i] <= data[j])
			{
				j--;
			}
		}
		merge(data,start,mid,end);
	}

	void merge(vector<int>&data, int start, int mid, int end)
	{
		if (end <= start)
			return;
		vector<int> temp;
		int i = start, j = mid + 1;
		while (i <= mid && j <= end)
		{
			if (data[i] <= data[j])
			{
				temp.push_back(data[i]);
				i++;
			}
			else
			{
				temp.push_back(data[j]);
				j++;
			}
		}
		while (i <= mid)
		{
			temp.push_back(data[i]);
			i++;
		}
		while (j <= end)
		{
			temp.push_back(data[j]);
			j++;
		}
		for (int k = 0; k < temp.size(); k++)
			data[start + k] = temp[k];
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> v = {8,1,2,7,3,4,9};
	int res = so.InversePairs(v);
	cout << res << endl;

	system("pause");
	return 0;
}
*/