#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(vector<string> lines) {
	int answer = 0;

	// 같은 날짜만 체크를 위한 변수
	string chusuckDate = "";
	// 날짜, 시간, 작업 시간을 split 해서 저장
	string date, time, working;
	// 시간과 작업시간을 int로 변환해서 밀리초로 환산을 위한 변수
	int hour, minute, second, workingTime;
	// 처리량 비교를 위한 변수
	vector<pair<int, int>> check;

	for (int i = 0; i < lines.size(); ++i)
	{
		// 같은 날짜인지 체크, 만약 다른 날짜면 제외시킨다 (추석이라는 특정 날짜 이므로...)
		stringstream ss1(lines[i]);
		getline(ss1, date, ' ');
		if (chusuckDate.empty())
			chusuckDate = date;
		else if (date.compare(chusuckDate) != 0)
			continue;
		
		// 시간과 작업시간을 저장
		getline(ss1, time, ' ');
		getline(ss1, working, ' ');

		// 시간을 밀리초로 변환
		stringstream ss2(time);
		getline(ss2, time, ':');
		hour = stoi(time) * 60 * 60 * 1000;
		getline(ss2, time, ':');
		minute = stoi(time) * 60 * 1000;
		getline(ss2, time, ':');
		float sec = stof(time) * 1000;
		// float은 0.001정도의 오차가 있어서 반올림으로 보정
		second = round(sec);
				
		// 작업 시간을 밀리초로 변환 -1은 딱겹치는 부분 제외
		workingTime = stof(working) * 1000 - 1;

		int endTime = hour + minute + second;
		pair<int, int> data;
		// 작업 시작 시간
		data.first = endTime - workingTime;
		// 작업 종료 시간
		data.second = endTime;

		check.push_back(data);
	}

	for (int i = 0; i < check.size(); ++i)
	{
		int checkCnt = 0;

		// 체크 범위
		int checkTime = check[i].first - 999;

		for (int j = 0; j < check.size(); ++j)
		{
			// 현재시간과 체크 시간 사이에 범위가 있는 경우
			if (checkTime <= check[j].first && check[j].first <= check[i].first)
				checkCnt++;
			// 시작과 종료 사이에 범위가 포함
			else if (checkTime >= check[j].first && check[j].second >= checkTime)
				checkCnt++;
		}

		// 이전에 체크 한것보다 크면 갱신
		if (answer < checkCnt)
			answer = checkCnt;
	}

	return answer;
}

int main()
{
	vector<string> lines = {
		"2016-09-15 20:59:57.421 0.351s",
		"2016-09-15 20:59:58.233 1.181s",
		"2016-09-15 20:59:58.299 0.8s",
		"2016-09-15 20:59:58.688 1.041s",
		"2016-09-15 20:59:59.591 1.412s",
		"2016-09-15 21:00:00.464 1.466s",
		"2016-09-15 21:00:00.741 1.581s",
		"2016-09-15 21:00:00.748 2.31s",
		"2016-09-15 21:00:00.966 0.381s",
		"2016-09-15 21:00:02.066 2.62s"
	};

	int result = solution(lines);
	cout << result << endl;
	cout << endl;

	system("pause");
	return 0;
}
