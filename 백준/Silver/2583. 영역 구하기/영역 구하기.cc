#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{

	int m; // 열
	int n; // 행

	int k; // 직사각형 개수

	cin >> n >> m >> k;

	vector<vector<bool>> space; // true - 색칠 됨, false - 색칠 안 됨.
	space.resize(n);

	int spaceCnt = 0;
	vector<int> out;

	for (int i = 0; i < n; ++i)
		space[i].resize(m);

	for (int i = 0; i < k; ++i) // 직사각형 공간 true 칠하기
	{
		int x1;
		int y1;
		int x2;
		int y2;

		cin >> x1 >> y1;
		cin >> x2 >> y2;

		for (int j = x1; j < x2; ++j)
		{
			for (int l = y1; l < y2; ++l)
			{
				space[l][j] = true;
			}
		}
	}

	queue<pair<int, int>> qq; // n , m
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!space[i][j]) // false 색칠되지 않은 영역!
			{
				qq.push(make_pair(i,j));
				space[i][j] = true;

				++spaceCnt; // 영역이 하나 생김 , 영역 카운트 ++.
				out.push_back(1); // 영역 넓이 구하기 시작. !!

				while (!qq.empty())
				{
					pair<int, int> now = qq.front();
					qq.pop();
					pair<int, int> up = { now.first - 1, now.second };
					pair<int, int> right = { now.first, now.second + 1 };
					pair<int, int> down = { now.first + 1, now.second };
					pair<int, int> left = { now.first, now.second - 1 };

					if ((right.second < m) && !space[right.first][right.second])
					{
						qq.push(right);
						space[right.first][right.second] = true;
						++out[spaceCnt - 1];
					}
					if ((down.first < n) && !space[down.first][down.second])
					{
						qq.push(down);
						space[down.first][down.second] = true;
						++out[spaceCnt - 1];
					}
					if ((0 <= left.second) && !space[left.first][left.second])
					{
						qq.push(left);
						space[left.first][left.second] = true;
						++out[spaceCnt - 1];
					}
					if ((0 <= up.first) && !space[up.first][up.second])
					{
						qq.push(up);
						space[up.first][up.second] = true;
						++out[spaceCnt - 1];
					}
				}

			}

		}
	}

	cout << spaceCnt << endl;
	sort(out.begin(), out.end());
	for (int i = 0; i < out.size(); ++i)
		cout << out[i] << " ";

	return 0;
}


//for (int i = 0; i < space.size(); ++i)
//{
//	for (int j = 0; j < space[0].size(); ++j)
//		cout << space[i][j];

//	cout << endl;
//}