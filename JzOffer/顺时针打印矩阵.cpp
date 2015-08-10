#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> res;
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int m = matrix.size();
		if (m == 0)
			return res;
		int n = matrix[0].size();
		int end = (min(m,n) + 1)/2;
		bool **visited = new bool*[m];
		for (int i = 0; i < m; i++)
			visited[i] = new bool[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = false;
		for (int i = 0; i < end; i++)
		{
			print(matrix,visited,i,m-2*i,n-2*i);
		}
		for (int i = 0; i < m; i++)
			delete[] visited[i];
		delete[] visited;
		return res;
	}

	void print(vector<vector<int>> &matrix, bool** visited ,int start, int rowlen, int collen)
	{
		if (rowlen <= 0 || collen <= 0)
			return;

		for (int j = start; j < start + collen;j++)
			if (!visited[start][j])
			{
				visited[start][j] = true;
				res.push_back(matrix[start][j]);
			}
		for (int i = start; i < start + rowlen;i++)
			if (!visited[i][start + collen - 1])
			{
				visited[i][start+collen-1] = true;
				res.push_back(matrix[i][start+collen-1]);
			}
		for (int j = start + collen - 1; j >= start; j--)
			if (!visited[start + rowlen - 1][j])
			{
				visited[start + rowlen - 1][j] = true;
				res.push_back(matrix[start+rowlen-1][j]);
			}
		for (int i = start + rowlen - 1; i >= start;i--)
			if (!visited[i][start])
			{
				visited[i][start] = true;
				res.push_back(matrix[i][start]);
			}
	}

};