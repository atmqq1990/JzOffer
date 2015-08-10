#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> st;
		int len = pushV.size();
		if (len == 0)
			return false;
		int pushindex = 0;
		int popindex = 0;
		while (popindex < len)
		{
			while (st.empty() || pushindex<len && st.top()!=popV[popindex])
			{
				st.push(pushV[pushindex]);
				pushindex++;
			}
			
			if (st.top() != popV[popindex])
				return false;
			st.pop();
			popindex++;
		}
		
		return true;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<int> pushV = {1,2,3,4,5};
	vector<int> popV = {4,3,5,1,2};
	bool res = so.IsPopOrder(pushV,popV);
	cout << res << endl;
	
	system("pause");
	return 0;
}
*/