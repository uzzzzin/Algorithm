#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M; // 바구니, 공
	cin >> N >> M;

	vector<int> v(N + 1,0);

	for (int i = 0; i < M; ++i)
	{
		int beg, end, n;
		cin >> beg >> end >> n;
		
		for (int j = beg; j <= end; ++j)
			v[j] = n;
	}

	for (int i = 1; i < N + 1; ++i)
		cout << v[i] << " ";

	return 0;
}