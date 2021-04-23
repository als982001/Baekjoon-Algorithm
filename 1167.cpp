#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct node
{
	int to; // 여기까지의
	int distance; // 거리
};

vector<node> vec[100001];
bool check[100001];
int v;
int cur, target_node, dist; // 순서대로 현재 노드, 현재 노드와의 거리를 나타내는 노드, 둘 사이의 거리
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
	cin >> v;

	for (int i = 0; i < v; ++i)
	{
		cin >> cur;
		cin >> target_node;
		while (target_node != -1)
		{
			cin >> dist;
			vec[cur].push_back({ target_node, dist });
			cin >> target_node;
		}
	}

	DFS(1, 0); // 임의의 노드를 시작으로 해서 가장 먼 노드를 조사한다
	memset(check, 0, sizeof(check));
	DFS(farthest_node, 0);
	cout << farthest_distance << endl;

	return 0;
}