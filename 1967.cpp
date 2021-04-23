#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct node
{
	int to; // 여기까지의
	int distance; // 거리
};

vector<node> vec[10001];
bool check[10001];
int n;
int parent, child, dist;
int farthest_node; // 임의의 노드에서 가장 먼 노드
int farthest_distance; // 임의의 노드에서 가장 먼 거리 겸 지름으로 사용할 변수

void DFS(int x, int dist)
{
	if (check[x])
		return;
	if (farthest_distance < dist)
	{
		farthest_distance = dist;
		farthest_node = x;
	}

	check[x] = true;

	for (int i = 0; i < vec[x].size(); ++i)
	{
		int y = vec[x][i].to;
		DFS(y, dist + vec[x][i].distance);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> parent >> child >> dist;
		vec[parent].push_back({ child, dist });
		vec[child].push_back({ parent, dist });
	}

	DFS(1, 0); // 임의의 노드를 시작으로 해서 가장 먼 노드를 조사한다

	memset(check, 0, sizeof(check));
	DFS(farthest_node, 0);
	cout << farthest_distance << endl;

	return 0;
}