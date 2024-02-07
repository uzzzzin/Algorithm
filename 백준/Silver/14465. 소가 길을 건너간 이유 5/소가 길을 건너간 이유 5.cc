#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int n, k, b; // 횡단보도 개수, 연속되고 싶은 신호등 개수, 고장난 신호등 개수
	cin >> n >> k >> b;

	vector<bool> crosswalk(n, true); // 멀쩡한 신호등은 true, 고장난 신호등은 false

	for (int i = 0; i < b; ++i)
	{
		int tmp;
		cin >> tmp;
		crosswalk[tmp - 1] = false;
	}

	int cur = k;
	int min = k;

	for (int i = 0; i < n; ++i)
	{
		if (i + k > n) // 벡터 인덱스 범위 넘어감.
			break;

		if (n == i + k) // 끝에 도달
		{
			cur = 0;
			for (int j = i; j < i + k; ++j)
			{
				if (false == crosswalk[j])
				{
					++cur;
					//crosswalk[j] = true;
				}
			}
		}
		else
		{
			if (false == crosswalk[i + k]) // 막혀있다
			{
				cur = 0;
				for (int j = i; j < i + k; ++j)
				{
					if (false == crosswalk[j])
					{
						++cur;
						//crosswalk[j] = true;
					}
				}
			}
		}
		
		if (min > cur)
			min = cur;
	}

	cout << min;

	return 0;
}