#include<iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int spacecount = 0;
		for (int i = 0; i<length; i++)
			if (str[i] == ' ')
				spacecount++;
		str[length + 2 * spacecount] = '\0';
		int i = length - 1;
		while (spacecount > 0)
		{

			if (str[i] != ' ')
			{
				str[i + 2 * spacecount] = str[i];
			}
			else if (str[i] == ' ')
			{
				spacecount--;
				str[i + 2 * spacecount] = '%';
				str[i + 2 * spacecount + 1] = '2';
				str[i + 2 * spacecount + 2] = '0';
			}
			i--;
		}
	}
};