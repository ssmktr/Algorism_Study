#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
	long long answer = 0;

	/*
		인덱스	넓이		이전 넓이와 차이
		1		4
		2		6		2
		3		10		4
		4		16		6
		5		26		10
		6		42		16
	*/

	vector<long long> circumference(N);
	circumference[0] = 4;
	circumference[1] = 6;
	for (int i = 2; i < N; ++i)
		circumference[i] = circumference[i - 1] + circumference[i - 2];

	answer = circumference[N - 1];

	return answer;
}

int main()
{
	int n = 5;
	long long result = solution(n);
	cout << result << endl;

	n = 6;
	result = solution(n);
	cout << result << endl;

	system("pause");
	return 0;
}