#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int tcase;
	cin >> tcase;

	vector<int> rv(tcase);

	for (int i = 0; i < tcase; ++i)
	{
		int n;
		cin >> n;
		vector<int> nn(n);
		vector<vector<int>> vv(2, nn);

		for (int j = 0; j < n; ++j)
			cin >> vv[0][j];

		for (int j = 0; j < n; ++j)
			cin >> vv[1][j];

		if (1 == n)
		{
			rv[i] = max(vv[0][0], vv[1][0]);
			continue;
		}

		vector<vector<int>> dp(2, nn);

		dp[0][0] = vv[0][0];
		dp[1][0] = vv[1][0];

		dp[0][1] = vv[0][1] + dp[1][0];
		dp[1][1] = vv[1][1] + dp[0][0];

		//cout << dp[0][1] << " " << dp[1][1] << endl;

		if (2 == n)
		{
			rv[i] = max(dp[0][1], dp[1][1]);
			continue;
		}

		if (n > 2)
		{
			for (int k = 2; k < n; ++k)
			{
				dp[0][k] = max(dp[1][k - 1], dp[1][k - 2]) + vv[0][k];
				dp[1][k] = max(dp[0][k-2],dp[0][k - 1]) + vv[1][k];

				//cout << dp[0][k] << " " << dp[1][k] << endl;
			}

			rv[i] = max(dp[0][n-1], dp[1][n-1]);
		}
	}

	for (int i = 0; i < tcase; ++i)
		cout << rv[i] << endl;

	return 0;
}

