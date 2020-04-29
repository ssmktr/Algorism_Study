#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
	vector<int> answer;

	for (int i = 0; i < n; ++i)
	{
		answer.push_back(0);

		vector<int> temp = answer;
		for (int j = temp.size() - 2; j >= 0; --j)
		{
			answer.push_back((temp[j] == 1 ? 0 : 1));
		}
	}

	return answer;
}

int main()
{
	vector<int> result = solution(3);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << ", ";

	cout << endl << endl;

	system("pause");
	return 0;
}
