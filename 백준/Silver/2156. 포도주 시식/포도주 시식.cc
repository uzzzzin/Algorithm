#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> dp(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	dp[0] = v[0];
	dp[1] = dp[0] + v[1];

	int m = v[0]+v[1];
	m = max(m, v[0] + v[2]);
	m = max(m, v[1] + v[2]);
	dp[2] = m;

	for (int i = 3; i < n; ++i)
	{
		int m = dp[i - 1];
		m = max(m, dp[i - 2] + v[i]);
		m = max(m, dp[i - 3] + v[i - 1] + v[i]);
		dp[i] = m;
	}

	cout << dp[dp.size() - 1];

	return 0;
}