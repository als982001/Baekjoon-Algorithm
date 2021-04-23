#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

int input_num, times, zero_idx;
char temp;
int nn[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
string map, temp_map;
string perfect = "123456780";
queue<pair<string, int>> q;
set<string> check;

bool IsIn(int r, int c)
{
	return 3 > r && r >= 0 && 3 > c && c >= 0;
}

void BFS()
{
	q.push(make_pair(map, 0));
	check.insert(map);

	while (!q.empty())
	{
		string cur = q.front().first;
		int cur_cnt = q.front().second;
		q.pop();

		if (cur == perfect)
		{
			times = cur_cnt;
			return;
		}
		
		zero_idx = cur.find('0');
		int cur_r = zero_idx / 3;
		int cur_c = zero_idx % 3;

		for (int i = 0; i < 4; ++i)
		{
			int nxt_r = cur_r + nn[i][0];
			int nxt_c = cur_c + nn[i][1];

			if (IsIn(nxt_r, nxt_c))
			{
				temp_map = cur;
				temp_map[zero_idx] = temp_map[nxt_r * 3 + nxt_c];
				temp_map[nxt_r * 3 + nxt_c] = '0';

				if (check.find(temp_map) == check.end())
				{
					check.insert(temp_map);
					q.push(make_pair(temp_map, cur_cnt + 1));
				}
			}
		}
	}

	times = -1;
}

int main()
{
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			cin >> input_num;
			temp = input_num + '0';
			map += temp;
		}
	}

	BFS();

	cout << times << endl;

	return 0;
}