#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int colors[20001];
queue<pair<int, int>> q;
vector<int> p[20001];
string result[6];

int k, v, e;
string res;

int Determine_Color(int c)
{
	if (c == 1)
		return 2;
	return 1;
}

string BFS()
{
	for (int i = 1; i <= v; ++i)
	{
		if (colors[i] == 0)
		{
			q.push(pair<int, int>(i, 2));
			colors[i] = 2;

			while (!q.empty())
			{
				int cn = q.front().first;
				int cc = q.front().second;
				q.pop();

				for (int j = 0; j < p[cn].size(); ++j)
				{
					int nn = p[cn][j];
					
					if (colors[nn] == 0)
					{
						int nc = Determine_Color(cc);
						colors[nn] = nc;
						q.push(pair<int, int>(nn, nc));
					}
				}
			}
		}
		else // 만약 해당 노드에 색이 칠해져 있으면
		{
			int clr = colors[i];
			int nn;
			for (int j = 0; j < p[i].size(); ++j)
			{
				nn = p[i][j];
				if (colors[nn] == clr)
					return "NO";
				
			}

		}
	}

	return "YES";
}

int main()
{
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		cin >> v >> e;

		for (int j = 0; j < e; ++j)
		{
			int a, b;
			cin >> a >> b;
			p[a].push_back(b);
			p[b].push_back(a);
		}
		result[i] = BFS();

		for (int i = 1; i <= v; ++i)
		{
			p[i].clear();
			colors[i] = 0;
		}
	}

	for (int i = 0; i < k; ++i)
	{
		cout << result[i] << endl;
	}
	return 0;
}