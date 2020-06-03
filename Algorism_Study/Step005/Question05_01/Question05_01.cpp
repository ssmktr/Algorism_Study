#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	// 배포날짜 저장
	vector<int> deploys;
	// 총 갯수
	int totalCnt = progresses.size();
	for (int i = 0; i < totalCnt; ++i)
	{
		// 진행도 
		int prog = progresses[i];
		// 하루 처리 비율
		int spd = speeds[i];

		// 남은 진행도
		int remainProg = 100 - prog;
		// 남은 날짜
		int remainSpd = remainProg / spd;
		// 남은 진행도랑 남은 날짜를 나눴을때 나머지가 있다면 하루 플러스 해준다
		if (remainProg % spd != 0)
			remainSpd++;

		for (int j = 0; j < deploys.size(); ++j)
		{
			// 이전 배포 날짜랑 비교해서 남은 날짜가 더 큰게 있다면 그날로 바꿔준다
			if (deploys[j] > remainSpd)
				remainSpd = deploys[j];
		}
		// 순서대로 남은 날짜 추가
		deploys.push_back(remainSpd);
	}

	// 오름 차순으로 정렬 ( 위에서 이미 낮은 순서로 집어 넣기 때문에 없어도 되는 코드 )
	sort(deploys.begin(), deploys.end());
	// 이전 배포 날짜 저장
	int prevDeploy = 0;
	for (int i = 0; i < deploys.size(); ++i)
	{
		// 이전 배포 날짜와 현재 배포 날짜가 같다면 이전 배포를 플러스 해준다
		if (prevDeploy == deploys[i])
			answer[answer.size() - 1]++;
		// 이전 배포 날짜와 현재 배포 날짜가 다르다면 배열에 추가 해준다
		else
			answer.push_back(1);

		// 이전 배포 날짜 새로 저장
		prevDeploy = deploys[i];
	}

	return answer;
}

int main()
{
	vector<int> progresses = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };

	vector<int> result = solution(progresses, speeds);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << ", ";
	cout << endl;

	system("pause");
	return 0;
}
