#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	vector<int> parent;
	parent.resize(n);
	// 맨처음에는 부모는 자기 자신이다.
	for (int i = 0; i < n; i++)
		parent[i] = i;

	// 가중치를 오름차순으로 소팅
	sort(costs.begin(), costs.end(), [=](vector<int> comp1, vector<int> comp2) 
	{
		return comp1[2] < comp2[2];
	});

	for (int i = 0; i < costs.size(); i++)
	{
		int start = costs[i][0];
		int end = costs[i][1];
		int cost = costs[i][2];

		// 시작의 최고 부모를 찾는다
		if (start != parent[start])
		{
			vector<int> idxs;
			int value = start;
			// 나 자신이 나올때까지 루프 돌면서 인덱스 저장
			while (value != parent[value])
			{
				idxs.push_back(value);
				value = parent[value];
			}

			// 모든 인덱스( 노드 )의 값을 최고 부모의 값으로 변경
			for (int i = 0; i < idxs.size(); ++i)
				parent[idxs[i]] = value;

			// 시작을 최고 부모로 변경
			start = value;
		}

		// 도착의 최고 부모를 찾는다
		if (end != parent[end])
		{
			vector<int> idxs;
			int value = end;
			// 나 자신이 나올때까지 루프 돌면서 인덱스 저장
			while (value != parent[value])
			{
				idxs.push_back(value);
				value = parent[value];
			}

			// 모든 인덱스( 노드 )의 값을 최고 부모의 값으로 변경
			for (int i = 0; i < idxs.size(); ++i)
				parent[idxs[i]] = value;

			// 도착을 최고 부모로 변경
			end = value;
		}
			
		// 시작과 도착이 같지않으면 코스트 증가
		if (start != end)
		{
			parent[end] = start;
			answer += cost;
		}

		cout << start << ", " << end << " ===> " << ((start != end) ? "ADD" : "COMPARE") << endl;
	}

	return answer;
}

int main()
{
	int n = 4;
	vector<vector<int>> costs = {
		{0,1,1},
		{0,2,2},
		{1,2,5},
		{1,3,1},
		{2,3,8}
	};

	int result = solution(n, costs);
	cout << result << endl;
	cout << endl;

	system("pause");
	return 0;
}