#include <iostream>
#include <vector>

using namespace std;

int dp[10001];

int main()
{
	int n, k; // 동전 개수, 가치 합
	cin >> n >> k;

	vector<int> v(n+1);

	for (int i = 1; i < n+1; ++i)
	{
		cin >> v[i];
	}

	for (int i = 1; i <= k; ++i)
	{
		dp[i] = 10001;
	}

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = v[i]; j <= k; ++j)
		{
			dp[j] = min(dp[j],dp[j - v[i]] + 1);
		}
	}

	if (10001 != dp[k])
		cout << dp[k];
	else
		cout << -1;

	return 0;
}