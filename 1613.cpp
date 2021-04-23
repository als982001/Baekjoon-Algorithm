#include <iostream>
#include <vector>
using namespace std;

bool incident[401][401]; // incident[a][b] => a가 b보다 앞에 있다
int n, k, s;
int front, back;
int isfront, isback;
vector<int> answer;

void Make_Sequence()
{
	for (int mid = 1; mid <= n; ++mid) // 가운데
	{
		for (int start = 1; start <= n; ++start) // 시작점
		{
			for (int end = 1; end <= n; ++end) // 끝점
			{
				if (incident[start][mid] && incident[mid][end])
					incident[start][end] = true;
			}
		}
	}
}

void Check_Front_Back(int fnt, int bck)
{
	if (incident[fnt][bck])
		answer.push_back(-1);
	else if (incident[bck][fnt])
		answer.push_back(1);
	else
		answer.push_back(0);
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < k; ++i)
	{
		//cin >> front >> back;
		scanf("%d %d", &front, &back);
        incident[front][back] = true;
	}
	Make_Sequence();

	cin >> s;
	for (int i = 0; i < s; ++i)
	{
		cin >> isfront >> isback;
		Check_Front_Back(isfront, isback);
	}

	for (int i = 0; i < answer.size(); ++i)
	{
        printf("%d\n", answer[i]);
		//cout << answer[i] << endl;
	}
	return 0;
}