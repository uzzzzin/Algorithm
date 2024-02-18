#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> vv(n, vector<int>(m));
    queue<pair<int, int>> qq;


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int n;
            cin >> n;
            if (n == 1)
                qq.push({ i,j });

            vv[i][j] = n;
        }
    }

    while (!qq.empty())
    {
        int nn = qq.front().first;
        int mm = qq.front().second;
        qq.pop();

        int day = vv[nn][mm];

        // 상
        if (nn - 1 >= 0 && 0 == vv[nn - 1][mm])
        {
            vv[nn - 1][mm] = day + 1;
            qq.push({ nn - 1, mm });
        }

        // 하 
        if (nn + 1 < n && 0 == vv[nn + 1][mm])
        {
            vv[nn + 1][mm] = day + 1;
            qq.push({ nn + 1, mm });

        }

        // 좌
        if (mm - 1 >= 0 && 0 == vv[nn][mm - 1])
        {

            vv[nn][mm - 1] = day + 1;
            qq.push({ nn, mm - 1 });

        }

        // 우
        if (mm + 1 < m && 0 == vv[nn][mm + 1])
        {
            vv[nn][mm + 1] = day + 1;
            qq.push({ nn, mm + 1 });

        }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (vv[i][j] == 0)
            {
                cout << -1;
                return 0;
            }

            ans = max(ans, vv[i][j]);
        }
    }

    cout << ans - 1;

    return 0;
}