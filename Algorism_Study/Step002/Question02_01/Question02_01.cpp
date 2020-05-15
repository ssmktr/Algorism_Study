#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool CheckFunc(char& c, vector<pair<char, bool>>& check)
{
	for (int i = 0; i < check.size(); ++i)
	{
		if (check[i].first == c)
			break;

		if (check[i].first != c && check[i].second == false)
			return false;
	}

	return true;
}

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	
	vector<pair<char, bool>> check;
	for (int j = 0; j < skill.size(); ++j)
	{
		pair<char, bool> data(skill[j], false);
		check.push_back(data);
	}

	for (int i = 0; i < skill_trees.size(); ++i)
	{
		int idx1 = -1;
		string temp1 = skill_trees[i];

		for (int j = 0; j < check.size(); ++j)
			check[j].second = false;

		for (int j = 0; j < temp1.size(); ++j)
		{
			int idx2 = skill.find(temp1[j]);
			if (idx1 < idx2)
			{
				if (!CheckFunc(temp1[j], check))
				{
					idx1 = -2;
					break;
				}

				idx1 = idx2;
				check[idx2].second = true;
			}
			else if(idx2 != -1)
			{
				idx1 = -2;
				break;
			}
		}

		if (idx1 >= -1)
			answer++;
	}

	return answer;
}

int main()
{
	vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };
	int result = solution("CBD", skill_trees);
	cout << result << endl;
	cout << endl;

	system("pause");
	return 0;
}