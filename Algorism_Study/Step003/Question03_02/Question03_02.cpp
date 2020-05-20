#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& computers, int n) {
	if (!computers[n][n])    
		return false;
	
	computers[n][n] = 0;
	for (int i = 0; i < computers.size(); i++) {
		if (computers[n][i])    
			dfs(computers, i);
	}

	return true;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (computers[i][i] && dfs(computers, i))        
			answer++;
	}

	return answer;
}

int main()
{
	vector<vector<int>> coputers = {
		{1,1,0},
		{1,1,0},
		{0,0,1}
	};
	int result = solution(3, coputers);
	cout << result << endl;

	system("pause");
	return 0;
}
