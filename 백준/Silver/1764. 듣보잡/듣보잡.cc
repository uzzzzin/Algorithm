#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N, M; // 듣x, 보x
	cin >> N >> M;

	map<string, bool> m;

	for (int i = 0; i < N; ++i)
	{
		string st;
		cin >> st;
		m.insert({st, false});
	}

	for (int i = 0; i < M; ++i)
	{
		string st;
		cin >> st;

		if (m.end() != m.find(st)) // 듣o이라면
			m[st] = true;
	}

	int msize = m.size();
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (false == it->second)
			--msize;
			
	}

	cout << msize << endl;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (true == it->second)
			cout << it->first << endl;
	}

	return 0;
}