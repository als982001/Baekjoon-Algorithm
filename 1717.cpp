#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sets[1000001];
vector<string> ans;
int n, m;
int k, a, b;

int Get_Parent(int p[], int x)
{
	if (p[x] == x)
		return x;
	else
		return p[x] = Get_Parent(p, p[x]);
}

void Union_Parent(int p[], int a, int b)
{
	a = Get_Parent(p, a);
	b = Get_Parent(p, b);
	if (a < b)
		p[b] = a;
	else
		p[a] = b;
}

string Find_Parent(int p[], int a, int b)
{
	a = Get_Parent(p, a);
	b = Get_Parent(p, b);
	if (a == b)
		return "YES";
	else
		return "NO";
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		sets[i] = i;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &k, &a, &b);

		if (k == 0)
		{
			Union_Parent(sets, a, b);
		}
		else
		{
			ans.push_back(Find_Parent(sets, a, b));
		}
	}

	for (int i = 0; i < ans.size(); ++i)
	{
        printf("%s\n", ans[i].c_str());
	}

	return 0;
}