#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int summm(int mid, int N, vector<int> v);

int main()
{
	int ret = 0;

	int N; // 지방 수
	cin >> N;

	vector<int> v(N);
	int sum = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());

	int M; // 총 예산
	cin >> M; 

	if (sum < M)
	{
		cout << v[N - 1];
		return 0;
	}
	else
	{
		int beg = 0;
		int end = v[N-1];

		int summ = 0;

		while (beg <= end)
		{
			int mid = (beg + end) / 2;
			int summ = summm(mid, N, v);

			if (M >= summ) 
			{
				beg = mid + 1; // 뒤
				ret = mid;
			}
			else 
			{
				end = mid - 1; // 앞
			}
		}
	}
	cout << ret;
	return 0;
}

int summm(int mid, int N, vector<int> v)
{
	int summmm = 0;
	for (int i = 0; i < N; ++i)
	{
		if (v[i] > mid) 
		{
			summmm += mid;
		}
		else 
		{
			summmm += v[i];
		}
	}
	return summmm;
}