#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string seats;
	cin >> seats;

	int cupCnt = 1;
	int manCnt = 0;

	for (int i = 0; i < seats.length(); ++i)
	{
		++manCnt;
		if ('S' == seats[i])
			++cupCnt;
		else if ('L' == seats[i])
		{
			if (i >= 1 &&'L' == seats[i - 1]) // 커플석
			{
				++cupCnt;
				seats[i] = 'X'; // 커플석 연석 막기용
			}
		}
	}
	if (manCnt > cupCnt)
		cout << cupCnt;
	else
		cout << manCnt;

	return 0;
}