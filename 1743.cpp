#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
int r, c;
int sz;

int map[101][101];
bool check[101][101];
int nn[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
queue<pair<int, int>> q;

bool IsIn(int r, int c)
{
	return n >= r && r >= 1 && m >= c && c >= 1;
}

void BFS()
{
	for (int r = 1; r <= n; ++r)
	{
		for (int c = 1; c <= m; ++c)
		{
			if (map[r][c] == 1 && !check[r][c])
			{
				int cur_size = 1;
				q.push(make_pair(r, c));
				check[r][c] = true;

				while (!q.empty())
				{
					int cur_r = q.front().first;
					int cur_c = q.front().second;
					q.pop();

					for (int i = 0; i < 4; ++i)
					{
						int nxt_r = cur_r + nn[i][0];
						int nxt_c = cur_c + nn[i][1];

						if (IsIn(nxt_r, nxt_c) && !check[nxt_r][nxt_c] && map[nxt_r][nxt_c] == 1)
						{
							++cur_size;
							check[nxt_r][nxt_c] = true;
							q.push(make_pair(nxt_r, nxt_c));
						}
					}
				}
				if (cur_size > sz)
					sz = cur_size;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i)
	{
		cin >> r >> c;
		map[r][c] = 1;
	}

	BFS();

	cout << sz << endl;

	return 0;
}