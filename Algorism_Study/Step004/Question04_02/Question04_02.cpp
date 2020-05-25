#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;



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