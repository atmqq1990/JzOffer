#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
	bool isNumeric(char* str)
	{
		int len = strlen(str);
		if (len == 0)
			return false;
		bool hase = false;
		bool haspoint = false;
		bool hasdigit = false;
		bool hassymbol = false;
		bool hasesymbol = false;
		int i = 0;
		if (str[i] == '+' || str[i] == '-')
		{
			hassymbol = true;
			i++;
		}

		for (; i < len;i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				hasdigit = true;
				continue;
			}
			if (str[i] == '+' || str[i] == '-')
			{
				if (hase && (str[i - 1] == 'E' || str[i - 1] == 'e') && hasesymbol == false)
				{
					hasesymbol = true;
					if (i == len - 1)
						return false;
				}
				else
					return false;
			}
			else if (str[i] == '.')
			{
				
				if (haspoint || hase)
					return false;
				haspoint = true;
			}
			else if (str[i] == 'E' || str[i] == 'e')
			{
				if (!hasdigit)
					return false;
				if (str[i - 1] == '.')
					return false;
				if (hase)
					return false;
				hase = true;
				if (i == len - 1)
					return false;
			}
			else
				return false;

		}
		
		return hasdigit;

	}

};


int main(int argc, char** args)
{
	Solution so;
	bool res = so.isNumeric("12e+1");
	cout << res << endl;
	
	system("pause");
	return 0;
}