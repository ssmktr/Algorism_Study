#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool CheckFunc(int idx, const vector<vector<int>>& computers, map<int, map<int, bool>>& check)
{
	// 나 자신이 이미 사용 됐는지 체크
	if (check[idx][idx] == true)
		return false;

	// 나 자신 사용했다고 변경
	check[idx][idx] = true;
	for (int i = 0; i < computers.size(); ++i)
	{
		// 이미 사용된 컴퓨터 인지 체크
		if (check[idx][i])
			continue;

		// 연결된 컴퓨터 인지 체크(1 : 연결됨, 0 : 연결 안됨)
		if (computers[idx][i] == 1)
			CheckFunc(i, computers, check);
	}

	return true;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	// 이미 체크 했는지 체크를 위한 STL
	map<int, map<int, bool>> check;

	for (int i = 0; i < n; ++i)
	{
		if (CheckFunc(i, computers, check))
			answer++;
	}

	return answer;
}

int main()
{
	int n = 3;
	vector<vector<int>> coputers = {
		{1,1,0},
		{1,1,0},
		{0,0,1}
	};
	int result = solution(n, coputers);
	cout << result << endl;

	n = 3;
	coputers = {
		{1,1,0},
		{1,1,1},
		{0,1,1}
	};
	result = solution(n, coputers);
	cout << result << endl;

	system("pause");
	return 0;
}
