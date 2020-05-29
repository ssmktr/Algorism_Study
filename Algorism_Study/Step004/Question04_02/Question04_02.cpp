#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	int max = 0;
	for (int i = 0; i < costs.size(); ++i)
	{
		int value = costs[i][1];
		if (value > max)
			max = value;
	}
	vector<int> parent;
	for (int i = 0; i <= max; ++i)
		parent.push_back(i);

	//sort(costs.begin(), costs.end(), [=](vector<int> comp1, vector<int> comp2) -> bool 
	//{
	//	return comp1[2] < comp2[2];
	//});

	vector<int> parent;


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