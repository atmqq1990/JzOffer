#include<iostream>
using namespace std;

class Solution {
public:
	int LastRemaining_Solution(unsigned int n, unsigned int m)
	{
		if (n<1 || m<1)
			return -1;
		if (m == 1)
			return n - 1;
		int visitednumber = 0;
		bool *visited = new bool[n];
		for (int i = 0; i<n; i++)
			visited[i] = false;
		int i = 0;
		int currentcount = 0;
		while (visitednumber < n - 1)
		{
			if (!visited[i])
				currentcount++;
			if (currentcount == m)
			{
				visited[i] = true;
				currentcount = 0;
				visitednumber++;
			}
			i++;
			if (i == n)
				i = 0;
		}
		int res = -1;
		for (int i = 0; i<n; i++)
			if (!visited[i])
			{
				res = i;
				break;
			}
		delete[] visited;
		return res;
	}
};