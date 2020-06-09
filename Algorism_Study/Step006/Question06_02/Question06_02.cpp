#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	/*
		1 :		1
		2 :		2
		3 :		3	2 + 1
		4 :		5	3 + 2
		5 :		8	5 + 3
	*/

	// 직사각형의 갯수 만큼 배열을 미리 만든다
	vector<int> vec(n);
	// 0번째와 1번째 인덱스는 미리 넣어 준다
	vec[0] = 1;
	vec[1] = 2;

	// 원하는 인덱스 까지만 루프를 돈다
	// 2번째 인덱스부터는 피보나치 수열로 연산하고 숫자가 너무 커지는 것을 방지하기 위해 1000000007의 나머지로 넣어준다
	for (int i = 2; i < n; ++i)
		vec[i] = (vec[i - 1] + (vec[i - 2])) % 1000000007;
	// 원하는 인덱스의 값을 가져온다
	answer = vec[n - 1];

	return answer;
}

int main()
{
	int n = 4;
	int result = solution(n);
	cout << result << endl;

	system("pause");
	return 0;
}