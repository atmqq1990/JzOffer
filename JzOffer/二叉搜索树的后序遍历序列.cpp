#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int len = sequence.size();
		if (len == 0)
			return false;
		if (len == 1)
			return true;
		return verify(sequence,0,len-1);

	}

	bool verify(vector<int>& sequence, int start, int end)
	{
		if (start >= end)
			return true;
		int rootvalue = sequence[end];
		int i = start;
		while (i < end && sequence[i] < rootvalue)
			i++;
		int j = i;
		while (j < end)
		{
			if (sequence[j] <= rootvalue)
				return false;
			j++;
		}

		return verify(sequence,start,i-1) && verify(sequence,i,end-1);
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> sequ = {1,4,3,7,10,9,6};
	bool res = so.VerifySquenceOfBST(sequ);
	cout << res << endl;

	system("pause");
	return 0;
}
*/