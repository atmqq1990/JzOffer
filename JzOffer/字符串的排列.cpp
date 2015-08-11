#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<string> res;
	vector<string> Permutation(string str) {
		if (str.size() == 0)
			return res;
		sort(str.begin(),str.end());
		permu(str,0);
		sort(res.begin(),res.end());
		return res;
	}

	void swap(string &str, int i, int j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

	void permu(string &str, int pos)
	{
		if (pos == str.size())
		{
			res.push_back(str);
			return;
		}
		unordered_set<char> swaped;
		for (int i = pos; i < str.size(); i++)
		{
			if (swaped.find(str[i]) != swaped.end())
				continue;
			swaped.insert(str[i]);
			swap(str,pos,i);
			permu(str,pos+1);
			swap(str,pos,i);
		}
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	vector<string> res = so.Permutation("abc");
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	
	system("pause");
	return 0;

}
*/