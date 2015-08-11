#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		vec.push_back(num);
	}

	double GetMedian()
	{
		int size = vec.size();
		if (size % 2 == 1)
			return get(0,size-1,size/2+1);
		int v1 = get(0, size - 1, size / 2);
		int v2 = get(0, size - 1, size / 2 + 1);
		return (v1 + v2) / 2.0;

	}

private:
	vector<int> vec;

	// find kth value in vec
	int get(int start, int end,int kth)
	{
		int index = partition(start,end);
		if (index == kth - 1)
			return vec[start+index];
		else if (index < kth - 1)
			return get(start+index + 1, end, kth - index - 1);
		else if (index > kth - 1)
			return get(start,start+index-1,kth);
	}

	int partition(int start, int end)
	{
		if (start >= end)
			return 0;
		int piovt = vec[start];
		int i = start, j = end;
		while (i < j)
		{
			while (i< j && vec[j] >= piovt)
				j--;
			if (i < j)
			{
				vec[i] = vec[j];
				i++;
			}
			while (i < j && vec[i] <= piovt)
				i++;
			if (i < j)
			{
				vec[j] = vec[i];
				j--;
			}
		}
		vec[i] = piovt;
		
		return i - start;
	}

	void swap(int i, int j)
	{
		int temp = vec[i];
		vec[i] = vec[j];
		vec[j] = temp;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	int arr[] = {1,4,9,3,2,3,5,6,7,0};
	for (int i = 0; i < 10; i++)
		so.Insert(arr[i]);
	double res = so.GetMedian();
	cout << res << endl;

	system("pause");
	return 0;
}
*/