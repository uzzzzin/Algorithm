#include <iostream>
#include <vector>
//#include <utility>

using namespace std;

int main()
{
    int C, N;
    cin >> C >> N;

    vector<int> dp(100001, 0);

    vector<pair<int, int>> vp; // cost, people

    for (int i = 0; i < N; ++i)
    {
        int cost, man;
        cin >> cost >> man;

        vp.push_back({ cost, man });
    }


    for (int i = 1; i < dp.size(); ++i)
    {
        for (int j = 0; j < vp.size(); ++j)
        {
            int cost = vp[j].first;
            int man = vp[j].second;

            if (cost <= i)
                dp[i] = max(dp[i], dp[i - cost] + man);

            // 현재 도시를 선택 x
            dp[i] = max(dp[i], dp[i - 1]);
        }

        if (C <= dp[i])
        {
            cout << i;
            break;
        }
    }
    return 0;
}