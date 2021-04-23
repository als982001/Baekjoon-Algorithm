#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
int v;
bool cb[1001];
bool cd[1001];
vector<int> a[1001];

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	cb[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";
        sort(a[x].begin(), a[x].end());
		for (int i = 0; i < a[x].size(); ++i)
		{
			int y = a[x][i];
			if (!cb[y])
			{
				cb[y] = true;
				q.push(y);
			}
		}

	}
}

void DFS(int x)
{
	if (cd[x])
		return;
	cd[x] = true;
	cout << x << " ";
    sort(a[x].begin(), a[x].end());
	for (int i = 0; i < a[x].size(); ++i)
	{
		int y = a[x][i];
		DFS(y);
	}
}
int main()
{
	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	DFS(v);
	cout << endl;
	BFS(v);
	return 0;
}