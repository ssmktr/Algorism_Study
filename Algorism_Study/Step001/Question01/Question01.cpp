#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights)
{
	vector<int> answer;

	answer.resize(heights.size());
	for (int j = 0; j < answer.size(); ++j)
	{
		int value = heights[j];
		answer[j] = 0;
		for (int i = j; i >= 0; --i)
		{
			if (value < heights[i])
			{
				value = heights[i];
				answer[j] = i + 1;
				break;
			}
		}
	}

	return answer;
}

int main()
{
	vector<int> heights = { 6, 9, 5, 7, 4 };
	vector<int> result = solution(heights);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << ", ";
	cout << endl << endl;

	system("pause");
	return 0;
}
