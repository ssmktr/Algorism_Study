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
		vec[i] = (vec[i - 1] + vec[i - 2] + vec[i - 2]) % 10007;
	}

	cout << vec[n] << endl;

	return 0;
}