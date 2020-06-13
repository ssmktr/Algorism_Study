#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string p) {
	string answer = "";

	// 비어 있으면 그냥 출력
	if (p.empty())
		return answer;

	// 괄호를 제외한 문자 삭제
	string check = "";
	for (int i = 0; i < p.size(); ++i)
	{
		if (p[i] == '(' || p[i] == ')')
			check += p[i];
	}
	p = check;

	// 왼쪽 괄호
	vector<char> left;
	// 오른쪽 괄호
	vector<char> right;
	int totalCnt = p.size();
	for (int i = 0; i < totalCnt; ++i)
	{
		// 지금 인덱스와 다음 인덱스가 완벽한 괄호를 이룬다면 출력
		if (p[i] == '(' && p[i + 1] == ')')
		{
			answer += "()";
			// 다음 인덱스까지 사용했으므로 인덱스를 증가한다
			i++;
			continue;
		}

		// 왼쪽 괄호를 넣는다
		if (p[i] == '(')
		{
			// 왼쪽괄호는 배열에 넣고 그린다
			left.push_back(p[i]);
			answer += "(";
		}
		else if (p[i] == ')')
		{
			// 오른쪽 괄호는 일단 배열에 넣어둔다
			right.push_back(p[i]);
		}

		// 왼쪽과 오른쪽 괄호의 갯수가 같아지면 오른쪽 괄호를 전부 그린다
		if (left.size() == right.size())
		{
			for (int j = 0; j < right.size(); ++j)
				answer += right[j];

			// 다 사용했으면 배열에서 삭제
			left.clear();
			right.clear();
		}
	}

	return answer;
}

int main()
{
	string p = "(()())()";
	string result = solution(p);
	cout << result << endl;

	p = ")(";
	result = solution(p);
	cout << result << endl;

	p = "()))((()";
	result = solution(p);
	cout << result << endl;

	system("pause");
	return 0;
}
