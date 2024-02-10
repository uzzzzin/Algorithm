#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	priority_queue<int> pq;
	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;

		if (tmp > 0)
			pq.push(tmp);

		else if (tmp == 0)
		{
			if (pq.empty())
				v.push_back(0);
			else
			{
				v.push_back(pq.top());
				pq.pop();
			}
		}
	}

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << '\n';

	return 0;
}