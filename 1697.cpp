#include <iostream>
#include <queue>

using namespace std;
int check[100001];
queue<int> q;
int cur;
int nt;
int n, k;

void BFS()
{
	
	q.push(n);
	check[n] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 3; ++i)
		{
			if (i == 0)
				nt = cur + 1;
			else if (i == 1)
				nt = cur - 1;
			else
				nt = cur * 2;

			if (nt >= 0 && nt <= 100000 && check[nt] == 0 && nt != n)
			{
				check[nt] = check[cur] + 1;
				q.push(nt);
				//if (nt == k)
					//return;
			}
		}
	}
}

int main()
{
	cin >> n >> k;
 
    BFS();

	cout << check[k] << endl;


	return 0;
}