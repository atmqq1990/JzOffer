#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len == 0)
			return 0;
		if (rotateArray[0] < rotateArray[len - 1])
			return rotateArray[0];
		int low = 0, high = len - 1;
		int mid;
		while (high - low > 1)
		{
			mid = (low + high) / 2;
			if (rotateArray[mid] > rotateArray[high])
				low = mid;
			else if (rotateArray[mid] < rotateArray[high])
				high = mid;
			else if (rotateArray[mid] == rotateArray[high])
			{
				if (rotateArray[mid] > rotateArray[low])
					high = mid;
				else if (rotateArray[mid] < rotateArray[low])
					low = mid;
				else if (rotateArray[mid] == rotateArray[low])
					low++;
			}
		}

		return min(rotateArray[low], rotateArray[high]);

	}
};