#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 현재 배우려는 스킬보다 앞부분의 스킬을 배웠는지 체크
bool CheckFunc(char& c, vector<pair<char, bool>>& check)
{
	for (int i = 0; i < check.size(); ++i)
	{
		// 현재 스킬부분이면 빠져나간다
		if (check[i].first == c)
			break;

		// 현재 배우려는 스킬은 아닌데 배운게 아니라면 false로 리턴
		if (check[i].first != c && check[i].second == false)
			return false;
	}

	return true;
}

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	
	// skill의 앞부분 체크하려고 미리 자료구조를 만들어 둔다
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

		// 배우려는 스킬들의 배웠는지 체크를 일단 모두 초기화
		for (int j = 0; j < check.size(); ++j)
			check[j].second = false;

		for (int j = 0; j < temp1.size(); ++j)
		{
			// 현재 배우려는 스킬이 들어있고 몇번째인지 가져온다
			int idx2 = skill.find(temp1[j]);
			if (idx1 < idx2)
			{
				// 앞부분의 스킬 배웠는지 체크
				if (!CheckFunc(temp1[j], check))
				{
					idx1 = -2;
					break;
				}

				// 문제 없으면 idx값을 갱신
				idx1 = idx2;
				// 배웠으므로 배웠다고 true로 변경
				check[idx2].second = true;
			}
			// idx2가 -1 이면 리스트에 없기때문에 그냥 배우면 된다
			// idx2가 -1 이 아닌데 idx1보다 작거나 같은것이면 순서가 잘못된 것이므로 빠져나간다
			else if(idx2 != -1)
			{
				idx1 = -2;
				break;
			}
		}

		// -1보다 커야만 제대로 갱신된 데이터 이므로 answer를 올려준다
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