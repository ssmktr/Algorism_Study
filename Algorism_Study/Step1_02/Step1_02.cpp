#include <iostream>
#include <vector>

using namespace std;

int main()
{
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
		/*
			0		1
			1		1
			2		3			1 + (1 * 2)
			3		5			3 +	(1 * 2)
			4		11			5 + (3 * 2)
			5		21			11 + (5 * 2)
			6		43			21 + (11 * 2)
			7		85			43 + (21 * 2)
			8		171			85 + (43 * 2)
			9		341			171 + (85 * 2)
			10		683			341 + (171 * 2)
			11		1365		683 + (341 * 2)
			12		2731		1365 + (683 * 2)
			
			이전 데이터 + (이전전 데이터 * 2)
			위의 규칙으로 구해서 10007로 나눈다
		*/
		vec[i] = (vec[i - 1] + (vec[i - 2] * 2)) % 10007;
	}

	cout << vec[n] << endl;

	return 0;
}