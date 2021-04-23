#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
vector<int> p[101];
int bn[101];
bool check[101];

int n, m;

int BFS()
{
	int min = 100000000;
	int min_num;
	int howmany = 0;

	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
		bn[i] = 0;

		while (!q.empty())
		{
			int cn = q.front();
			q.pop();
			for (int j = 0; j < p[cn].size(); ++j)
			{
				int nn = p[cn][j];
				if (!check[nn])
				{
					check[nn] = true;
					bn[nn] = bn[cn] + 1;
					q.push(nn);
				}
			}
		}
	
		for (int j = 1; j <= n; ++j)
		{
			if (j != i)
				howmany += bn[j];
		}
		
		if (min > howmany)
		{
			min = howmany;
			min_num = i;
		}
		howmany = 0;
		for (int j = 1; j <= n; ++j)
		{
			check[j] = 0;
			bn[j] = 0;
		}
	}

	return min_num;
}

int main()
{
	cin >> n >> m;
	int a, b;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		p[a].push_back(b);
		p[b].push_back(a);
	}

	int min = BFS();
	cout << min << endl;

	return 0;
}