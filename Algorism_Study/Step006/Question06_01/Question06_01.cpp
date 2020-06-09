#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	// 위치와 값 저장 stl
	vector<pair<int, int>> check;
	// 값을 내림 차순으로 체크위한 stl
	vector<int> sortCheck;

	// 모든 stl을 저장
	for (int i = 0; i < priorities.size(); ++i)
	{
		check.push_back(pair<int, int>(i, priorities[i]));
		sortCheck.push_back(priorities[i]);
	}

	// 우선순위를 위해 내림 차순으로 정렬
	sort(sortCheck.begin(), sortCheck.end(), [](int comp1, int comp2) 
	{
		return comp1 > comp2;
	});

	// 우선순위에 들어있는 사이즈가 0이 될때까지 루프 돈다
	while (sortCheck.size() != 0)
	{
		// 위치와 값의 처음 값을 가져온다
		int idx = check[0].first;
		int value = check[0].second;

		// 비교할 위치와 값을 가져 왔기때문에 일단 뺀다
		check.erase(check.begin());
		// 앞부분 부터 비교
		if (value == sortCheck[0])
		{
			// 비교 해서 처리된 값은 뺀다
			sortCheck.erase(sortCheck.begin());
			answer++;

			// 위치가 같으면 원하는 값이므로 탈출
			if (location == idx)
				break;
		}
		// 비교한 값이 다르면 빼낸 값을 맨위로 다시 넣는다
		else
		{
			check.push_back(pair<int, int>(idx, value));
		}
	}

	return answer;
}

int main()
{
	vector<int> priorities = { 2,1,3,2 };
	int location = 2;
	int result = solution(priorities, location);
	cout << result << endl;

	priorities = { 1, 1, 9, 1, 1, 1 };
	location = 0;
	result = solution(priorities, location);
	cout << result << endl;

	system("pause");
	return 0;
}