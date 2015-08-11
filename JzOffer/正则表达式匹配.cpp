#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		
		int plen = strlen(pattern);
		int slen = strlen(str);
		if (plen == 0 && slen!=0)
			return false;
		if (plen == 0 && slen == 0)
			return true;
		if (pattern[0] == '*')
			return false;
		
		
		bool **matched = new bool*[plen+1];
		for (int i = 0; i <= plen; i++)
			matched[i] = new bool[slen+1];
		for (int i = 0; i <= plen; i++)
			for (int j = 0; j <= slen; j++)
				matched[i][j] = false;
		matched[0][0] = true;
		for (int i = 2; i <= plen; i++)
			matched[i][0] = matched[i - 2][0] && pattern[i - 1] == '*';
		
		for (int i = 1; i <= plen; i++)
			for (int j = 1; j <= slen;j++)
				if (pattern[i - 1] != '*')
				{
					matched[i][j] = matched[i - 1][j - 1] && (pattern[i-1] == str[j-1] || pattern[i-1]=='.');
				}
				else
				{
					matched[i][j] = matched[i-2][j] || matched[i][j-1] && (pattern[i-2] == str[j-1] || pattern[i-2] == '.');				
				}
		bool res = matched[plen][slen];
		for (int i = 0; i <= plen; i++)
			delete[] matched[i];
		delete[] matched;
		return res;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	bool res = so.match("aaa", "ab*aa");
	cout << res << endl;

	system("pause");
	return 0;
}
*/