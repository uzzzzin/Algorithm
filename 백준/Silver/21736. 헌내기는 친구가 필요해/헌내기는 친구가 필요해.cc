#include <iostream>
#include <queue>
#include <string>

using namespace std;



int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n,vector<char>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
	}
	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if ('I' == v[i][j])
				q.push({ i, j });
		}
	}

	int ans = 0;

	while (!q.empty())
	{
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		

		// 상 v[row-1][col] == 'O'
		if (row - 1 >= 0 && v[row - 1][col] == 'O')
		{
			v[row - 1][col] = '#';
			q.push({ row - 1, col });
		}

		// 하 v[row +1][col] 
		if (row + 1 < n && v[row + 1][col] == 'O')
		{
			v[row + 1][col] = '#';
			q.push({ row + 1, col });
		}

		// 좌 v[row][col-1]
		if (col -1 >= 0 && v[row][col-1] == 'O')
		{
			v[row][col-1] = '#';
			q.push({ row, col-1 });
		}

		// 우 v[row][col+1]
		if (col +1 < m && v[row][col+1] == 'O')
		{
			v[row][col+1] = '#';
			q.push({ row, col+1 });
		}


		// 상 v[row-1][col]
		if (row - 1 >= 0 && v[row - 1][col] == 'P')
		{
			v[row - 1][col] = '#';
			q.push({ row - 1, col });
			++ans;
		}

		// 하 v[row +1][col] 
		if (row + 1 < n && v[row + 1][col] == 'P')
		{
			v[row + 1][col] = '#';
			q.push({ row + 1, col });
			++ans;
		}

		// 좌 v[row][col-1]
		if (col - 1 >= 0 && v[row][col - 1] == 'P')
		{
			v[row][col - 1] = '#';
			q.push({ row, col - 1 });
			++ans;
		}

		// 우 v[row][col+1]
		if (col + 1 < m && v[row][col + 1] == 'P')
		{
			v[row][col + 1] = '#';
			q.push({ row, col + 1 });
			++ans;
		}


	}
	if (ans == 0)
		cout << "TT";
	else
		cout << ans;

	return 0;
}