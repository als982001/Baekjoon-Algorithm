#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int temp_map[9][9];
int map[9][9];
int check[9][9];
int nn[4][2] = { {1, 0}, {-1, 0},{0, 1},{0, -1} };

queue<pair<int, int>> q;

int N, M, temp;
int total_cnt;	// �� ������ ĭ ����
int zero_cnt;	// ó�� �Է� ���� ���� ���� ���� ����
int ans;		// ���� ��

bool IsIn(int r, int c)
{
	return N >= r && r >= 1 && M >= c && c >= 1;
}

void BFS()
{
	int safe_cnt = zero_cnt - 3;	// ���� 3�� ��ġ�� ��Ȳ�̱� ������ 3�� ����
	int virus = 0;

	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= M; ++c)
		{
			if (temp_map[r][c] == 2 && !check[r][c])
			{
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

						if (IsIn(nxt_r, nxt_c) && temp_map[nxt_r][nxt_c] == 0)
						{
							temp_map[nxt_r][nxt_c] = 2;
							check[nxt_r][nxt_c] = true;
							++virus;
							q.push(make_pair(nxt_r, nxt_c));
						}
					}
				}
			}
		}
	}
	if (safe_cnt - virus > ans)
	{
		ans = safe_cnt - virus;

	}
}

void Build_Wall(int R, int C, int wall_cnt)
{
	if (wall_cnt == 3)
	{
		memcpy(temp_map, map, sizeof(map));
		BFS();

		for (int i = 0; i < 9; ++i)
			memset(check[i], 0, 9 * sizeof(int));
		return;
	}

	for (int r = R; r <= N; ++r)
	{
		for (int c = 1; c <= M; ++c)
		{
			if (map[r][c] == 0)		// check �� �־ ���� �ʳ�?????
			{
				map[r][c] = 1;

				if (c == M)
					Build_Wall(r + 1, 0, wall_cnt + 1);
				else
					Build_Wall(r, c + 1, wall_cnt + 1);

				map[r][c] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	total_cnt = N * M;

	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= M; ++c)
		{
			cin >> temp;
			map[r][c] = temp;
			if (temp == 0)
				++zero_cnt;
		}
	}

	Build_Wall(1, 1, 0);

	cout << ans << endl;

	return 0;
}
