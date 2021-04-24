#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;

int prime[10000];
int check[10000];
int nn[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

queue<pair<string, pair<int, int>>> q;	// 순서대로 4자리 비밀번호, 바꾼 자리 위치, 바꾼 횟수
vector<int> result;
int T;
string from, to;

void Make_Prime()
{
	for (int start = 2; start < 10000; ++start)
		prime[start] = start;

	for (int start = 2; start < 10000; ++start)
	{
		if (prime[start] == 0)
			continue;
		for (int not_prime = start + start; not_prime < 10000; not_prime += start)
		{
			prime[not_prime] = 0;
		}
	}
}

void BFS()
{
	q.push(make_pair(from, make_pair(-1, 0)));
	check[stoi(from)] = true;

	while (!q.empty())
	{
		string cur = q.front().first;
		int changed_location = q.front().second.first;
		int cur_times = q.front().second.second;
		q.pop();

		if (cur == to)
		{
			result.push_back(cur_times);
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			if (i == changed_location)
				continue;

			for (int nn = 0; nn < 10; ++nn)
			{
				if (i == 0 && nn == 0)
					continue;
				string temp = cur;

				if (temp[i] - 48 != nn)
				{
					temp[i] = nn + 48;

					if (prime[stoi(temp)] != 0 && cur_times < check[stoi(temp)])
					{
						check[stoi(temp)] = cur_times + 1;
						q.push(make_pair(temp, make_pair(i, cur_times + 1)));
					}
				}
			}
		}
	}

}

int main()
{
	Make_Prime();

	cin >> T;

	while (T > 0)
	{
		--T;
		memset(check, 10000, sizeof(int) * 10000);
		cin >> from;
		cin >> to;

		BFS();
		while (!q.empty())
			q.pop();
	}

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;

	return 0;
}