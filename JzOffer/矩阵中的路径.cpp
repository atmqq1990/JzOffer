#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
	bool found = false;
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (rows <= 0 || cols <= 0)
			return false;
		if (strlen(str) == 0)
			return false;
		bool **visited = new bool*[rows];
		for (int i = 0; i < rows; i++)
			visited[i] = new bool[cols];
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				visited[i][j] = false;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (found)
					return true;
				if (matrix[i*cols + j] != str[0])
					continue;
				findpath(matrix,visited,i,j,rows,cols,str,0);
				if (found)
					return true;
			}

		}

		return found;
	}

	void findpath(char* matrix, bool** visited ,int rowid, int colid, int rowlen, int collen, char* str, int pos)
	{
		if (rowid < 0 || rowid >= rowlen || colid < 0 || colid >= collen)
			return;

		if (found)
			return;
		int strlength = strlen(str);
		if (pos == strlength-1)
		{
			found = true;
			return;
		}
		visited[rowid][colid] = true;
		
		// up 
		if (rowid > 0 && !visited[rowid - 1][colid] && matrix[(rowid - 1)*collen + colid] == str[pos + 1])
			findpath(matrix, visited, rowid - 1, colid, rowlen,collen,str,pos+1);
		if (found)
			return;

		//right
		if (colid < collen - 1 && !visited[rowid][colid + 1] && matrix[rowid*collen + colid + 1] == str[pos + 1])
			findpath(matrix,visited,rowid,colid+1,rowlen,collen,str,pos+1);
		if (found)
			return;

		//down
		if (rowid < rowlen - 1 && !visited[rowid + 1][colid] && matrix[(rowid + 1)*collen + colid] == str[pos + 1])
			findpath(matrix,visited,rowid+1,colid,rowlen,collen,str,pos+1);
		if (found)
			return;

		//left
		if (colid > 0 && !visited[rowid][colid - 1] && matrix[rowid*collen + colid - 1] == str[pos + 1])
			findpath(matrix,visited,rowid,colid-1,rowlen,collen,str,pos+1);
		if (found)
			return;

		visited[rowid][colid] = false;
	}

};

/*
int main(int argc, char** args)
{
	Solution so;
	bool res = so.hasPath("ABCESFCSADEE", 3, 4, "ABCCED");
	cout << res << endl;

	system("pause");
	return 0;
}
*/