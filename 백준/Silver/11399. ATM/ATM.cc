#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = v[0];
	for (int i = 1; i < v.size(); ++i)
	{
		v[i] += v[i - 1];
		sum += v[i];
	}

	cout << sum;

	return 0;
}