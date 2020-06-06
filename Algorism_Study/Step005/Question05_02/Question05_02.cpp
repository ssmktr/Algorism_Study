#include <iostream>
#include <map>
#include <set>

using namespace std;

// 기본 자리수에 해당하는 숫자
int insertDefaultValue(const int& N, int cnt)
{
	int temp = 0;
	for (int i = 0; i < cnt; ++i)
		temp = temp * 10 + N;

	return temp;
}

// 현재까지 중에 있는지 체크
bool find(int& number, map<int, set<int>>& check, int cnt)
{
	bool isIn = false;

	set<int> temp = check[cnt];
	for (auto& val : temp)
	{
		// 있으면 탈출
		if (val == number)
		{
			isIn = true;
			break;
		}
	}

	return isIn;
}

int solution(int N, int number) {
	int answer = -1;
	
	const int MAX_IDX = 9;
	map<int, set<int>> check;
	// 1개 일때는 그냥 넣는다
	set<int> setCheck;
	setCheck.insert(N);

	check[1] = setCheck;;

	if (find(number, check, 1))
	{
		answer = 1;
		return answer;
	}

	// 2개 일때는 사칙연산만 한다
	setCheck.clear();
	setCheck.insert(insertDefaultValue(N, 2));
	setCheck.insert(N + N);
	setCheck.insert(N - N);
	setCheck.insert(N * N);
	if (N != 0)
		setCheck.insert(N / N);

	check[2] = setCheck;

	if (find(number, check, 2))
	{
		answer = 2;
		return answer;
	}

	// 3개 일때는 2개째에서 앞뒤로 사칙연산만 한다
	setCheck.clear();
	setCheck.insert(insertDefaultValue(N, 3));
	for (auto & value : check[2])
	{
		setCheck.insert(N + value);
		setCheck.insert(N - value);
		setCheck.insert(N * value);
		if (value != 0)
			setCheck.insert(N / value);

		setCheck.insert(value + N);
		setCheck.insert(value - N);
		setCheck.insert(value * N);
		if (N != 0)
			setCheck.insert(value / N);
	}

	check[3] = setCheck;

	if (find(number, check, 3))
	{
		answer = 3;
		return answer;
	}

	// 4개 부터는 
	// 마지막꺼에서 앞뒤로 사칙연산 한다
	// 이미 있는 애들끼리 갯수에 맞게 연산한다
	for (int i = 4; i < MAX_IDX; ++i)
	{
		setCheck.clear();
		setCheck.insert(insertDefaultValue(N, i));
		for (auto & value : check[i - 1])
		{
			setCheck.insert(N + value);
			setCheck.insert(N - value);
			setCheck.insert(N * value);
			if (value != 0)
				setCheck.insert(N / value);

			setCheck.insert(value + N);
			setCheck.insert(value - N);
			setCheck.insert(value * N);
			if (N != 0)
				setCheck.insert(value / N);
		}

		for (int j = 1; j < i; ++j)
		{
			// i + j = i가 되는 모든 경우 연산 (예 : 5번째 계산 할때 i : 2, j : 3 또는 i : 3, j : 2)
			set<int> temp1 = check[i - j];
			set<int> temp2 = check[j];

			for (auto& val1 : temp1)
			{
				for (auto& val2 : temp2)
				{
					setCheck.insert(val1 + val2);
					setCheck.insert(val1 - val2);
					setCheck.insert(val1 * val2);
					if (val2 != 0)
						setCheck.insert(val1 / val2);

					setCheck.insert(val2 + val1);
					setCheck.insert(val2 - val1);
					setCheck.insert(val2 * val1);
					if (val1 != 0)
						setCheck.insert(val2 / val1);
				}
			}
		}

		check[i] = setCheck;

		if (find(number, check, i))
		{
			answer = i;
			break;
		}
	}

	return answer;
}

int main()
{
	int n = 5;
	int number = 12;
	int result = solution(n, number);
	cout << result << endl;

	n = 2;
	number = 11;
	result = solution(n, number);
	cout << result << endl;

	system("pause");
	return 0;
}