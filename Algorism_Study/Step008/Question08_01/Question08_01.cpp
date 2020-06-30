#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	int truck = 0;
	int totalCnt = truck_weights.size();
	while (truck_weights.size() != 0)
	{
		truck += truck_weights[0];
		truck_weights.erase(truck_weights.begin());

		answer++;
	}

	return answer;
}

int main()
{
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = { 7,4,5,6 };
	int result = solution(bridge_length, weight, truck_weights);
	cout << result << endl;

	system("pause");
	return 0;
}