#include <iostream>
#include <vector>

using namespace std;

int dp[10001][101];

int main()
{

	int N, M; 
	cin >> N;
	cin >> M;

	vector<pair<int, int>> vp;

	vp.push_back({ 0,0 });
	
	for (int i = 1; i <= N; ++i)
	{
		int byte;
		cin >> byte;
		vp.push_back({byte, 0});
	}

	for (int i = 1; i <= N; ++i)
	{
		int cost;
		cin >> vp[i].second;
	}

	for (int i = 0; i < 10001; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int byte = vp[j].first;
			int cost = vp[j].second;

			if (cost <= i)
				dp[i][j] = max( dp[i][j-1], dp[i-cost][j-1] + byte);
			else
				dp[i][j] = dp[i][j - 1];

			if (dp[i][j] >= M)
			{
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}