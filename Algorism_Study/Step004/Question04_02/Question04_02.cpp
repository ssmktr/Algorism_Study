#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find(int node, vector<int>& parent) // 경로 압축
{
	if (node == parent[node]) 
		return node;
	
	return parent[node] = find(parent[node], parent);
}

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
		int start = find(costs[i][0], parent);
		int end = find(costs[i][1], parent);
		int cost = costs[i][2];

		//int start = costs[i][0];
		//int end = costs[i][1];
		//int cost = costs[i][2];

		//while (true)
		//{
		//	if (start == parent[start])
		//		break;

		//	parent[start] = start;
		//}

		//while (true)
		//{
		//	if (end == parent[end])
		//		break;

		//	parent[end] = end;
		//}

		if (start != end)  // 사이클이 만들어지는지 체크! 
		{                  // 크루스칼알고리즘은 사이클이 만들어지지않을 때 추가한다.
			parent[start] = end;
			answer += cost;
		}
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