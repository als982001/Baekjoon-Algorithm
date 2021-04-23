#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> ranking;
int n;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;
		ranking.clear();

		for (int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			ranking.push_back(make_pair(a, b));
		}

		sort(ranking.begin(), ranking.end());
		
		int min = 100001;
		int count = 0;

		for (int i = 0; i < n; ++i)
		{
			if (min > ranking[i].second)
			{
				min = ranking[i].second;
				++count;
			}
		}
		cout << count << endl;
	}
}