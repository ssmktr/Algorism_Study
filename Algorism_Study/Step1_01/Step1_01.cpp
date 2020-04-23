#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 입력의 최대 값 제한
	const int MAX_SIZE = 1000000;
	// 입력 값
	int input;
	cin >> input;

	// 1보다 작거나 제한 된 최대값 보다 크면 예외처리
	if (input < 1 || input > MAX_SIZE)
		return 0;

	// 입력한 만큼만 메모리 생성 하기 위한 벡터
	vector<int> vec;
	// 입력한 값 + 1만큼 배열 생성( +1 하는 이유는 0 인덱스는 사용하지않고 입력값이랑 인덱스랑 맞추기 위함)
	vec.resize(input + 1);

	int size = vec.size();
	// 1은 0카운트라서 제외하고 2부터 시작
	for (int i = 2; i < size; ++i)
	{
		// 앞에서 부터 저장해왔기때문에 일단 현재 값은 이전 값에서 +1 해준다
		vec[i] = vec[i - 1] + 1;
		// 2로 나누어 떨어지면 현재 값과 2로 나누었을때 이미 저장되어있는 값이랑 크기 비교후 작은값 저장
		if (i % 2 == 0)
			vec[i] = min(vec[i], vec[i / 2] + 1);
		// 3로 나누어 떨어지면 현재 값과 3으로 나누었을때 이미 저장되어있는 값이랑 크기 비교후 작은값 저장
		if (i % 3 == 0)
			vec[i] = min(vec[i], vec[i / 3] + 1);
	}

	// 입력한 값(인덱스)까지 저장했으니 값 출력
	cout << vec[input] << endl;

	system("pause");
	return 0;
}
