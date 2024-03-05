#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main()
{
	int N, M; // 도시 수, 여행 계획 도시 수
	cin >> N >> M;

	vector<vector<int>> v(N+1, vector<int>(N+1));

	for (int i = 1; i <= N; ++i)
	{
		int cnt = 0;
		for (int j = 1; j <= N; ++j)
		{
			cin >> v[i][j];
		}
	}

	vector<int> co(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> co[i];
	}

	//map<int, int> m;
	queue<int> q;
	vector<bool> visited(201);

	int st = co[0];
	q.push(st);
	visited[st] = true;

	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();

		for (int i = 1; i <= N; ++i)
		{
			if ( 1 == v[tmp][i] && false == visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}

	}

	for (int i = 0; i < co.size(); ++i)
	{
		if (false == visited[co[i]])
		{
			cout << "NO";
			return 0;
		}	
	}
	cout << "YES";
	return 0;
}