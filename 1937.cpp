#include <iostream>
using namespace std;

int map[501][501];
int check[501][501];
int nn[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int n, k;

bool IsIn(int r, int c)
{
	return n >= r && r >= 1 && n >= c && c >= 1;
}

int Calculate_Days(int r, int c)
{
	if (check[r][c] != 0)
		return check[r][c];
	check[r][c] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int nr = r + nn[i][0];
		int nc = c + nn[i][1];

		if (IsIn(nr, nc))
		{
			if (map[nr][nc] > map[r][c])
			{
				check[r][c] = max(check[r][c], Calculate_Days(nr, nc) + 1);
			}
		}
	}
	return check[r][c];
}

void Obtain_The_Maximum_Number_of_Days()
{
	for (int r = 1; r <= n; ++r)
	{
		for (int c = 1; c <= n; ++c)
		{
			k = max(k, Calculate_Days(r, c));
		}
	}
}

int main()
{
	cin >> n;

	for (int r = 1; r <= n; ++r)
	{
		for (int c = 1; c <= n; ++c)
		{
			cin >> map[r][c];
		}
	}

	Obtain_The_Maximum_Number_of_Days();

	cout << k << endl;

	return 0;
}