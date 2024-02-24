#include <iostream>
#include <vector>

using namespace std;

int dp[1001][10];

int main()
{
	int T;
	cin >> T;

	vector<int> ans(T);
	int maxInt = 0;

	for (int i = 0; i < T; ++i)
	{
		cin >> ans[i];
		maxInt = max(ans[i], maxInt);
	}

	for (int i = 0; i < 10; ++i)
		dp[1][i] = 1;

	for (int i = 2; i <= maxInt; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			switch (j)
			{
				case 0:
				{
					dp[i][j] = dp[i - 1][7];
					break;
				}
				case 1:
				{
					dp[i][j] = dp[i - 1][2] + dp[i - 1][4];
					break;
				}
				case 2:
				{
					dp[i][j] = dp[i - 1][1] + dp[i - 1][3] + dp[i-1][5];
					break;
				}
				case 3:
				{
					dp[i][j] = dp[i - 1][2] + dp[i - 1][6];
					break;
				}
				case 4:
				{
					dp[i][j] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7];
					break;
				}
				case 5:
				{
					dp[i][j] = dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i-1][8];
					break;
				}
				case 6:
				{
					dp[i][j] = dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9];
					break;
				}
				case 7:
				{
					dp[i][j] = dp[i - 1][0] + dp[i - 1][4] + dp[i - 1][8];
					break;
				}
				case 8:
				{
					dp[i][j] = dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9];
					break;
				}
				case 9:
				{
					dp[i][j] = dp[i - 1][6] + dp[i - 1][8];
					break;
				}
			}
			dp[i][j] %= 1234567;

		}
	}

	for (int i = 0; i < T; ++i)
	{
		int cur = ans[i];
		int ansInt = 0;

		for (int i = 0; i < 10; ++i)
		{
			ansInt += dp[cur][i];
		}

		ansInt %= 1234567;
		cout << ansInt << endl;
	}

	return 0;
}