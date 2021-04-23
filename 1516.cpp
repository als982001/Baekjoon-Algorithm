#include <iostream>
#include <vector>
#include <queue>

#define MAX 501

using namespace std;

int inDegree[MAX];
vector<int> a[MAX];
int req_time[MAX];
int n;
int result[MAX] = { 0, };
void topologySort()
{
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (inDegree[i] == 0)
		{
			result[i] = req_time[i];
			q.push(i);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		int x = q.front();
		q.pop();

		for (int j = 0; j < a[x].size(); ++j)
		{
			int y = a[x][j];
			result[y] = max(result[y], req_time[y] + result[x]);
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		cout << result[i] << endl;
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> req_time[i];
		while (1)
		{
			int x;
			cin >> x;
			if (x == -1)
				break;
			a[x].push_back(i);
			inDegree[i]++;
		}
	}
	topologySort();
}