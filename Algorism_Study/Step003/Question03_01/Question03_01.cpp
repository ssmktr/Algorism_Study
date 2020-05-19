#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); ++i)
	{
		// 가격이 떨어지지 않았을때 기대값
		int value = prices.size() - i - 1;
		// 현재 값의 다음 값부터 비교하기 때문에 i + 1
		for (int j = i + 1; j < prices.size(); ++j)
		{
			// 가격이 떨어지는 시점에 갱신
			if (prices[i] > prices[j])
			{
				value = j - i;

				// ?? 왜 뒤에값을 비교하지 않고 1번 떨어지는 시점에 break하는지는 모르겠음 ( 이거 없어야 한다 생각하는데 없으니 안되서 구글링 해보니 break넣으니까 성공 )
				break;
			}
		}
		answer.push_back(value);
	}

	return answer;
}

int main()
{
	vector<int> prices = { 1,2,3,2,3 };
	vector<int> result = solution(prices);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << ", ";
	cout << endl;

	system("pause");
	return 0;
}