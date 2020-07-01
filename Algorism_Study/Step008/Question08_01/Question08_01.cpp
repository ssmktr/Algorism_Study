#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	// 현재 다리를 건너는 트럭들의 총 무게
	int totalWeight = 0;
	// 현재 다리를 건너는 트럭들의 무게와 남은 거리
	vector<pair<int, int>> check;

	// 맨처음 액션을 취했을때0이 아니라 1이므로 1을 더해서 시작
	answer++;
	// 원래 있던 트럭들과 체크한 트럭들의 싸이즈가 모두 0이 되면 탈출
	while (truck_weights.size() != 0 || check.size() != 0)
	{
		// 맨앞의 트력이 존재
		// 현재 건너고 있는 트럭들의 총 무게와 대기중인 맨앞의 트럭의 무게를 계산해서 다리가 견디는 무게 체크
		if (truck_weights.size() > 0 && totalWeight + truck_weights[0] <= weight)
		{
			// 맨 앞에 대기 중인 트럭의 무게
			int curWeight = truck_weights[0];
			// 맨 앞에 대기 중인 트럭의 무게를 총 무게의 더한다
			totalWeight += curWeight;
			// 맨 앞에 대기 중이던 트럭의 무게와 다리길이를 추가 한다
			check.push_back(pair<int, int>(curWeight, bridge_length));

			// 맨 앞의 트럭을 추가 했으니 대기열에서 삭제
			truck_weights.erase(truck_weights.begin());
		}

		// 건너는 트럭들의 거리를 1씩 뺀다
		for (pair<int, int>& val : check)
			val.second--;

		// 맨처음 들어온 트럭의 거리가 0이 되면 다 건넌것이므로 뺀다
		if (check.size() > 0 && check[0].second <= 0)
		{
			// 건너고있는 총 트럭들의 무게에서 빠지는 트럭의 무게 만큼 뺀다
			totalWeight -= check[0].first;
			check.erase(check.begin());
		}

		answer++;
	}

	return answer;
}

int main()
{
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = { 7, 4, 5, 6 };
	int result = solution(bridge_length, weight, truck_weights);
	cout << result << endl;

	bridge_length = 100;
	weight = 100;
	truck_weights = { 10 };
	result = solution(bridge_length, weight, truck_weights);
	cout << result << endl;

	bridge_length = 100;
	weight = 100;
	truck_weights = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	result = solution(bridge_length, weight, truck_weights);
	cout << result << endl;

	system("pause");
	return 0;
}