#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs();

int main()
{
	int times;
	cin >> times;

	for (int i = 0; i < times; ++i)
		bfs();

	return 0;
}

void bfs()
{
	int n, m, choo;
	cin >> n >> m >> choo;

	vector<vector<bool>> vv(n, vector<bool>(m));

	for (int i = 0; i < choo; ++i)
	{
		int nn, mm;
		cin >> nn >> mm;
		vv[nn][mm] = true;
	}

	queue<pair<int, int>> qq;

	int ji = 0; // 배지렁이 개수

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (true == vv[i][j])
			{
				qq.push({ i,j });
				vv[i][j] = false;
				++ji;
			}

			while (!qq.empty())
			{
				int nn = qq.front().first;
				int mm = qq.front().second;
				qq.pop();

				// 상
				if (nn - 1 >= 0 && true == vv[nn - 1][mm])
				{
					vv[nn - 1][mm] = false;
					qq.push({ nn - 1, mm });
				}

				// 하 
				if (nn + 1 < n && true == vv[nn + 1][mm])
				{
					vv[nn + 1][mm] = false;
					qq.push({ nn + 1, mm });
				}

				// 좌
				if (mm - 1 >= 0 && true == vv[nn][mm - 1])
				{
					vv[nn][mm - 1] = false;
					qq.push({ nn, mm - 1 });
				}

				// 우
				if (mm + 1 < m && true == vv[nn][mm + 1])
				{
					vv[nn][mm + 1] = false;
					qq.push({ nn, mm + 1 });
				}
			}
		}
	}

	cout << ji << endl;
}
