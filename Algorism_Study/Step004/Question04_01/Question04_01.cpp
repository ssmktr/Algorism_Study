#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string arrangement) {
	int answer = 0;

	// 막대기의 왼족을 담는다
	queue<int> left;
	// 막대기의 범위를 저장
	vector<pair<int, int>> range;
	// 레이저를 쏘는 위치 저장
	vector<float> lager;

	for (int i = 0; i < arrangement.size(); ++i)
	{
		// 레이저 데이터 인지 체크
		bool isLager = false;
		if (i < arrangement.size() - 1)
		{
			// 괄호가 () 서로 붙어있다면 레이저
			if (arrangement[i] == '(' && arrangement[i + 1] == ')')
			{
				lager.push_back((i + i + 1) / 2.0f);
				// 레이저로 체크 했다는 체크
				isLager = true;

				// 레이저라면 다음 인덱스를 건너뛴다
				++i;
			}
		}

		// 레이저가 아니라면
		if(!isLager)
		{
			// 왼족은 queue에 넣는다
			if (arrangement[i] == '(')
				left.push(i);
			// 마지막에 넣은 왼쪽과 처음 나온 오른쪽은 서로 짝을 이루어 막대기가 된다
			else if (arrangement[i] == ')')
			{
				int leftValue = left.front();
				// 사용한 queue는 빼준다
				left.pop();
				// 오른쪽이면 queue의 처음의 넣은 데이터를 가져와서 range에 넣는다
				range.push_back(pair<int, int>(leftValue, i));
			}
		}
	}

	// 하나도 잘리지않은 막대기 갯수
	answer = range.size();
	for (int i = 0; i < range.size(); ++i)
	{
		for (int j = 0; j < lager.size(); ++j)
		{
			// 막대기의 왼쪽과 오른쪽을 기준으로 레이저 위치 체크
			if (range[i].first < lager[j] && range[i].second > lager[j])
				answer++;
		}
	}

	return answer;
}

int main()
{
	string str = "()(((()())(())()))(())";
	int result = solution(str);
	cout << result << endl;
	cout << endl;

	system("pause");
	return 0;
}