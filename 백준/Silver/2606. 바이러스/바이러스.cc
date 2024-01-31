#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int comNum; // 컴퓨터 개수
	int pairNum; // 쌍 개수

	cin >> comNum >> pairNum;

	vector<vector<int>> coms(comNum+1);
	vector<bool> visited(comNum+1, false); // true : 바이러스 걸린 거 이미 확인.

	int start;
	int end;

	for (int i = 0; i < pairNum; ++i)
	{
		cin >> start >> end;
		coms[start].push_back(end);
		coms[end].push_back(start);
	}

	queue<int> qq;
	visited[1] = true;
	qq.push(1);

	while (!qq.empty())
	{
		int cur = qq.front();
		qq.pop();
		
		for (int i = 0; i < coms[cur].size(); ++i)
		{
			int next = coms[cur][i];

			if (!visited[next]) // 바이러스 첫 확인일 때,
			{
				qq.push(next);
				visited[next] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 2; i < visited.size(); ++i)
	{
		if (visited[i] == true)
			++ans;
	}

	cout << ans;
	return 0;
}