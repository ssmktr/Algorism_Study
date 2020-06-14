#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	
	// 연산 후 교체할 값 저장
	int val = 0;
	// 추가할 임시 문자열
	string temp = "";
	while (n != 0)
	{
		// 3의 배수로 자리수가 올라가기때문에 무조건 3으로 나누게 된다
		val = n / 3;
		// 3으로 나누어 떨어지면 4가 추가 된다
		temp = "4";
		// 3으로 나누어 떨어 졌을때
		if (n % 3 == 0)
			val--; // 나온 값의 1을 빼주어야 하는 규칙이 있다
		else
			temp = to_string(n % 3); // 3으로 나누어 떨어지지않는다면 값 그대로 추가 하면 된다

		// 원래 값에서 추가 되는 값을 앞으로 추가 헤준다
		answer = temp + answer;
		// 원래 값을 갱신 한다
		n = val;
	}

	return answer;
}

int main()
{
	for (int i = 1; i <= 10; ++i)
	{
		string result = solution(i);
		cout << result << ", ";
	}
	cout << endl;

	system("pause");
	return 0;
}