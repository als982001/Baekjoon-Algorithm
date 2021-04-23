#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

bool check[MAX];
int eaten[MAX];
vector<int> sk[MAX];

bool dfs(int s)
{
	for (int i = 0; i < sk[s].size(); ++i)
	{
		int f = sk[s][i];

		if (check[f])
			continue;
		check[f] = true;

		if (eaten[f] == 0 || dfs(eaten[f]))
		{
			eaten[f] = s;
			return true;
		}
	}
	return false;

}

int main()
{
	int n;
	cin >> n;
	int** stat = new int* [n + 1];
	for (int i = 0; i < n + 1; ++i)
	{
		stat[i] = new int[3];
	}

	for (int i = 1; i <= n; ++i)
	{
		cin >> stat[i][0] >> stat[i][1] >> stat[i][2];
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			if (stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2])
				sk[i].push_back(j);
			else if (stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2])
				sk[i].push_back(j);
			else if (stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2])
				sk[j].push_back(i);
		}
	}

	int count = 0;

	for (int k = 0; k < 2; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			fill(check, check + MAX, false);
			if (dfs(i))
				++count;
		}
	}

	for (int i = 0; i < n + 1; ++i)
	{
		delete[] stat[i];
	}
	delete[] stat;
	cout << n - count << endl;

	return 0;
}
