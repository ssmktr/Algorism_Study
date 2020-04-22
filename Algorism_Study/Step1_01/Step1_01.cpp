#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	const int MAX_SIZE = 10000000;
	vector<int> vec;
	int n;
	cin >> n;
	if (n < 1 || n > MAX_SIZE)
		return 0;

	vec.resize(n + 1);
	int size = (int)vec.size();
	for (int i = 0; i < size; ++i)
		vec[i] = 0;

	for (int i = 2; i <= n; ++i)
	{
		vec[i] = vec[i - 1] + 1;
		if (i % 2 == 0)
			vec[i] = min(vec[i], vec[i / 2] + 1);
		if (i % 3 == 0)
			vec[i] = min(vec[i], vec[i / 3] + 1);
	}

	cout << vec[n] << endl;

	return 0;
}