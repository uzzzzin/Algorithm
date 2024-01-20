
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int maxVal = 0;
vector<pair<int, int>> tp; // t : 상담 기간, p : 수익

void recur(int cur, int curVal)
{
    if (cur >= tp.size())
        return;

    // 오늘 상담 합니다
    if (tp.size() >= cur + tp[cur].first)
    {
        recur(cur + tp[cur].first, curVal + tp[cur].second);
        maxVal = max(curVal + tp[cur].second, maxVal);
    }

    // 오늘 상담 안 합니다
    if (tp.size() >= cur + 1)
    {
        recur(cur + 1, curVal);
        maxVal = max(curVal, maxVal);
    }

    //maxVal =
}

int main()
{
    cin >> n;
    tp.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> tp[i].first >> tp[i].second;

    int cur = 0;
    int curVal = 0;

    recur(cur, curVal);

    cout << maxVal;

    return 0;
}