#include <iostream>
#include <algorithm>

using namespace std;

int seat[11];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;

		int count = 0; // i번째 사람 왼쪽 중 키 큰 사람들 수
		for (int j = 1; j <= n; ++j)
		{
			// 입력 받은 숫자랑 왼쪽 키 큰 사람들 수 같으면서
			// 해당 자리가 비어있으면 그 자리에 넣는다.
			if (count == num && seat[j] == 0)
			{
				seat[j] = i;
				break;
			}
			// 자리가 비어있다는 것은 그 자리는
			// i번째 사람보다 큰 사람의 자리라는 것이므로
			// count를 1증가시킨다.
			if (seat[j] == 0)
				++count;
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << seat[i] << " ";

	return 0;
}