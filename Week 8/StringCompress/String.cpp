#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

int solution(string s) {
	int answer = 0;
	int loop = 1; //쪼개는 등분의 수
	vector<int> result; //loop마다 쪼개서 나오는 압축 길이 저장

	if (s.length() == 1)
		return 1;
	else
	{
		while (loop <= s.length() / 2)
		{
			int measure = 0;
			int count = 0; //문자열 추출 시작 위치
			string tmp = ""; //추출한 문자열 임시 저장 -> test queue에 투입
			int num = 1;
			string tpa = s.substr(0, loop);
			count += loop;

			for (measure; measure < (s.length() / loop); measure++)
			{
				if (tpa == s.substr(count, loop))
					++num;
				else
				{
					if (num == 1)
						tmp = tmp + tpa;
					else
						tmp = tmp + to_string(num) + tpa;
					num = 1;
					tpa = s.substr(count, loop);
				}
				count += loop; //시작 위치 갱신
			} //쪼개서 저장하기

			int nam = (s.length() % loop); //나머지 길이 추출
			result.push_back(tmp.length() + nam);
			loop++;
		}
		answer = *min_element(result.begin(), result.end());
		return answer;
	}
}