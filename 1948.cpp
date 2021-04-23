#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10001

class Edge
{
public:
	int node;
	int takentime;
	Edge(int n, int t) : node(n), takentime(t) {}
};

vector<Edge> fwd[MAX]; // 정방향
vector<Edge> rvs[MAX]; // 역방향
int result[MAX]; // 출발지점에서 해당 도시까지 걸리는 시간
int inDegree[MAX]; // 해당 도시를 가리키는 선의 개수
int check[MAX]; // 역순으로 조사할 때의 조사 여부 체크
int dpt; // 시작 도시
int des; // 도착 도시

void topologySort()
{
	queue<int> q; // 위상 정렬으 큐를 사용한다.
	q.push(dpt);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int j = 0; j < fwd[x].size(); ++j)
		{
			Edge y = Edge(fwd[x][j].node, fwd[x][j].takentime);
			if (result[y.node] <= y.takentime + result[x])
				result[y.node] = y.takentime + result[x];
			if (--inDegree[y.node] == 0)
				q.push(y.node);
		}
	}

	int count = 0;
	q.push(des);

	while (!q.empty())
	{
		int y = q.front();
		q.pop();

		for (int i = 0; i < rvs[y].size(); ++i)
		{
			Edge x = Edge(rvs[y][i].node, rvs[y][i].takentime);
			if (result[y] - result[x.node] == x.takentime)
			{
				++count;
				if (check[x.node] == 0)
				{
					q.push(x.node);
					check[x.node] = 1;
				}
			}
		}
	}
	cout << result[des] << endl << count;
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;

	int start, end, t;

	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end >> t;

		fwd[start].push_back(Edge(end, t));
		rvs[end].push_back(Edge(start, t));
		inDegree[end]++;
	}

	cin >> dpt >> des;
	topologySort();
	
	return 0;
}