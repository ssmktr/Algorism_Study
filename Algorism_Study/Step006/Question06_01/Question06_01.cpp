#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = priorities.size() - 1;

	vector<int> check;

	int idx = 0;
	while (priorities.size() != 0)
	{
		int value = priorities[idx];
		for (int i = idx; i < priorities.size(); ++i)
		{
			if (priorities[i] > value)
				idx = i;
		}

		check.push_back(priorities[idx]);
		priorities.erase(priorities.begin() + idx);

		idx--;
		if (idx >= priorities.size())
			idx = 0;
	}

	for (int i = 0; i < check.size(); ++i)
	{
		if (check[i] == location)
		{
			answer = i;
			break;
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