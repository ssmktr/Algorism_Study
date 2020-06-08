#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	const int MAX_SIZE = 1000;
	if (n < 1 || n > MAX_SIZE)
		return 0;

	vector<int> vec;
	vec.resize(n + 1);

	vec[0] = 1;
	vec[1] = 1;

	int size = (int)vec.size();
	for (int i = 2; i < size; ++i)
	{
		vec[i] = (vec[i - 1] + (vec[i - 2] * 2)) % 10007;
	}

	return answer;
}

int main()
{
	//int n = 4;
	//int result = solution(n);
	//cout << result << endl;

	const int MAX_SIZE = 1000;
	int n = 0;
	cin >> n;

	if (n < 1 || n > MAX_SIZE)
		return 0;

	vector<int> vec;
	vec.resize(n + 1);

	vec[0] = 1;
	vec[1] = 1;

	int size = (int)vec.size();
	for (int i = 2; i < size; ++i)
	{
		vec[i] = (vec[i - 1] + (vec[i - 2] * 2)) % 10007;
	}

	cout << vec[n] << endl;

	system("pause");
	return 0;
}