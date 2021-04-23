#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q; // BFS에서 사용하는 큐
int field[51][51]; // 배추가 심어져 있는 밭 (1이면 배추 있는 거)
int check[51][51]; // r,c 칸을 체크했는지 기록하는 배열 (0이면 체크 안한 거)
int nx[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; // 상하좌우
int t; // 테스트 케이스 개수
int m, n; //m은 가로 길이, n은 세로 길이
int k; // 배추가 심어져 있는 위치의 개수
int cr, cc; // 현재 기준이 되는 행, 열
int nr, nc; // 상하좌우로 검사할 행, 열
int howmany[1260];

bool isin(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}

void clear()
{
	for (int r = 0; r <= 50; ++r)
	{
		for (int c = 0; c <= 50; ++c)
		{
			field[r][c] = 0;
			check[r][c] = 0;
		}
	}
}

void BFS(int t)
{
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < m; ++c) // 필드를 순서대로 검사하다가 
		{
			// 배추가 심어져 있으면서 한 번도 검사한 적이 없는 칸이 있으면
			// 그 칸을 start로 해서 BFS를 시작한다
			if (field[r][c] == 1 && check[r][c] == 0) 
			{
				++howmany[t];
				q.push(pair<int, int>(r, c));
				check[r][c] = true;

				while (!q.empty())
				{
					cr = q.front().first;
					cc = q.front().second;
					q.pop();

					for (int i = 0; i < 4; ++i)
					{
						nr = cr + nx[i][0];
						nc = cc + nx[i][1];

						if (isin(nr, nc) && field[nr][nc] == 1 && check[nr][nc] == 0)
						{
							check[nr][nc] = 1;
							q.push(pair<int, int>(nr, nc));
						}
					}
				}
			}
		}
	}
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> m >> n >> k;

		for (int i = 0; i < k; ++i)
		{
			int r, c;
			cin >> c >> r;
			field[r][c] = 1;
		}
		BFS(i);
		clear();
	}

	for (int i = 0; i < t; ++i)
		cout << howmany[i] << endl;

	return 0;
}