#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int len = data.size();
		if (len == 0)
			return 0;
		if (k < data[0] || k > data[len - 1])
			return 0;
		int middle = binary_search(data,0,len-1,k);
		if (middle == -1)
			return 0;
		int left = middle;
		int temp1 = binary_search(data,0,left-1,k);
		while (temp1 != -1)
		{
			left = temp1;
			temp1 = binary_search(data, 0, left - 1, k);
		}
		int right = middle;
		int temp2 = binary_search(data,right+1,len-1,k);
		while (temp2 != -1)
		{
			right = temp2;
			temp2 = binary_search(data, right + 1, len - 1, k);
		}
		return right - left + 1;
	}

	int binary_search(vector<int>& data, int start, int end, int target)
	{
		int low = start;
		int high = end;
		int mid;
		while(low <= high)
		{
			mid = (low+high)/2;
			if (data[mid] == target)
				return mid;
			else if (data[mid] > target)
				high = mid - 1;
			else if (data[mid] < target)
				low = mid + 1;
		}
		return -1;
	}

};