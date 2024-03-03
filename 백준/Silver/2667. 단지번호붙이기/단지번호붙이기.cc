#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N));

	queue<pair<int, int>> q;

	vector<int> ans;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); ++j)
		{
			v[i][j] = str[j] - '0';
		}
	}


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (1 == v[i][j])
			{
				q.push({i,j});
				v[i][j] = 0;

				int cnt = 0;

				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;

					cnt++;
					q.pop();

					if (y-1 >=0 && 1 == v[y-1][x])
					{
						q.push({y-1,x});
						v[y-1][x] = 0;
					}

					if (y+1 < N  && 1 == v[y + 1][x])
					{
						q.push({ y + 1,x });
						v[y + 1][x] = 0;
					}
					if (x- 1 >= 0 && 1 == v[y][x-1])
					{
						q.push({ y,x-1 });
						v[y][x-1] = 0;
					}
					if (x+ 1 < N && 1 == v[y][x+1])
					{
						q.push({ y,x+1 });
						v[y][x+1] = 0;
					}

				}
				ans.push_back(cnt);
			}
		}
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;

	return 0;
}