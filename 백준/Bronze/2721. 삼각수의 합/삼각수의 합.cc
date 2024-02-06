#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int size;
	cin >> size;

	vector<int> testcase(size);

	for (int i = 0; i < size; ++i)
		cin >> testcase[i];

	for (int i = 0; i < size; ++i)
	{
		int ans = 0;
		int t = 1;

		for (int j = 1; j <= testcase[i]; ++j)
		{
			ans += j * (t + (j + 1));
			t = t + (j + 1);
		}
		cout << ans << endl;
	}

	return 0;
}