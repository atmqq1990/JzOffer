#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold < 0)
			return 0;
		if (threshold == 0)
			return 1;
		queue<pair<int, int>> qu;
		qu.push(pair<int,int>(0,0));
		int totalcount = 0;

		bool **visited = new bool*[rows];
		for (int i = 0; i < rows; i++)
			visited[i] = new bool[cols];
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				visited[i][j] = false;
		visited[0][0] = true;

		while (!qu.empty())
		{
			pair<int, int> cur = qu.front();
			qu.pop();
			totalcount++;
			int currow = cur.first;
			int curcol = cur.second;
			//up 
			if (currow > 0 && !visited[currow - 1][curcol] && digitsum(currow - 1) + digitsum(curcol) <= threshold)
			{
				visited[currow - 1][curcol] = true;
				qu.push(pair<int,int>(currow-1,curcol));
			}
			//right
			if (curcol < cols-1 && !visited[currow][curcol+1] && digitsum(currow) + digitsum(curcol+1) <= threshold)
			{
				visited[currow][curcol+1] = true;
				qu.push(pair<int, int>(currow, curcol+1));
			}
			//down 
			if (currow < rows-1 && !visited[currow+1][curcol] && digitsum(currow+1) + digitsum(curcol) <= threshold)
			{
				visited[currow+1][curcol] = true;
				qu.push(pair<int, int>(currow+1, curcol));
			}
			//left
			if (curcol > 0 && !visited[currow][curcol - 1] && digitsum(currow) + digitsum(curcol - 1) <= threshold)
			{
				visited[currow][curcol - 1] = true;
				qu.push(pair<int, int>(currow, curcol - 1));
			}

		}

		for (int i = 0; i < rows; i++)
			delete[] visited[i];
		delete[] visited;

		return totalcount;
	}

	int digitsum(int a)
	{
		if (a == 0)
			return 0;
		int sum = 0;
		int lastvalue = 0;
		while (a != 0)
		{
			lastvalue = a % 10;
			a = a / 10;
			sum += lastvalue;
		}
		return sum;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	int res = so.movingCount(5,10,10);
	cout << res << endl;

	system("pause");
	return 0;
}
*/