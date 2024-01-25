#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<int> all(1003002); // idx 0 - 1003001
// 백만보다 큰 제일 작은 소수 1003001

void eratos()
{
    all[0] = -1;
    all[1] = -1;
    for (int i = 2; i < 1003002; ++i)
    {
        if (-1 == all[i])
            continue;
        else
        {
            for (int j = i * 2; j < 1003002; j = j + i)
                all[j] = -1;
        }
    }
    return;
}

int palin(int cur)
{
    //if (-1 == all[cur])
    //    return -1;

    string numStr = to_string(cur);

    for (int i = 0; i < numStr.length()/2; ++i)
    {
        if (numStr[i] != numStr[numStr.length() - i - 1])
            return -1;
    }
    return cur;
}

int main()
{
    cin >> n;

    for (int i = 0; i < 1003002; ++i)
        all[i] = i;

    eratos();

    int max = 0;
    for (int i = n; i < 1003002; ++i)
    {
        int tmp = palin(all[i]);
        if (tmp != -1 && tmp > max)
        {
            cout << tmp;
            break;
        }
    }
    return 0;
}
