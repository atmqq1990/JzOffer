#include<iostream>
using namespace std;

class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		times[ch]++;
		str.push_back(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (int i = 0; i < str.size(); i++)
			if (times[str[i]] == 1)
				return str[i];
		return '#';
	}
private:
	int times[256] = {0};
	string str;
};