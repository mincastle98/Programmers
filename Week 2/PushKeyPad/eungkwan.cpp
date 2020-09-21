#include <string>
#include <vector>
#include <algorithm>
#include <cmath> //절댓값 함수, bar사용을 위해
#include <utility> //pair로 서로 다른 타입의 값을 저장할 때 사용, 원래는 이걸로 string, int 로 할랬는데 결국엔 int, int로 해서 필요 없어짐, 무시 ㅇㅇ
using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	vector<pair<int, int>> pad(12); //키패드 좌표
	vector<pair<int, int>> special(2); //손 짝
	pad[0] = make_pair(0, 1); //0의좌표 미리 정의
	int a = 3, b = 0; //최초의 좌표값 미리 설정함
	for (int i = 1; i < 10; i++) //for문으로 좌표값을 pair<int, int>형태로 vector에 차곡차곡 저장, vector[0] = 0의 좌표값, vector[1] = 1의 좌표값 이렇게 표현이 가능하다
	{
		if (b == 3)
		{
			b = 0;
			a--;
		}
		pad[i] = make_pair(a, b);
		b++;
	}
	special[0] = make_pair(0, 2); //오른손
	special[1] = make_pair(0, 0); //왼손

	for (int i = 0; i < numbers.size(); i++)
	{
		if ((numbers[i] % 3 == 0) && numbers[i] != 0)//3, 6, 9를 만나면 R이 문자열에 기록됨
		{
			answer += "R";
			special[0].first = pad[numbers[i]].first; //손의 위치는 수시로 갱신되어야 함, stack을 쓸까 했는데, 이게 더 쉽고, 값도 매번 바뀌는거니까 그냥 이렇게 함
			special[0].second = pad[numbers[i]].second;
		}
		else if (numbers[i] % 3 == 1)//1, 4, 7 만나면 L이 문자열에 기록됨
		{
			answer += "L";
			special[1].first = pad[numbers[i]].first;
			special[1].second = pad[numbers[i]].second; //위랑 same
		}
		else if ((numbers[i] % 3 == 2) || numbers[i] == 0)//2, 5, 8, 0을 만나는 경우
		{
			int right_d, left_d;
			right_d = abs(special[0].first - pad[numbers[i]].first) + abs(special[0].second - pad[numbers[i]].second); //오른손과 키패드의 거리를 계산(절댓값이용)
			left_d = abs(special[1].first - pad[numbers[i]].first) + abs(special[1].second - pad[numbers[i]].second); //똑같이 왼손의 경우도 
			if (right_d > left_d) //거리가 왼손으로 하는게 짧으면 L기록
			{
				answer += "L";
				special[1].first = pad[numbers[i]].first;
				special[1].second = pad[numbers[i]].second;
			}
			else if (right_d < left_d) //반대의 경우라면 R기록
			{
				answer += "R";
				special[0].first = pad[numbers[i]].first;
				special[0].second = pad[numbers[i]].second;
			}
			else //만약 같으면 주된 손을 선택
			{
				if (hand == "right")
				{
					answer += "R";
					special[0].first = pad[numbers[i]].first;
					special[0].second = pad[numbers[i]].second;
				}
				else
				{
					answer += "L";
					special[1].first = pad[numbers[i]].first;
					special[1].second = pad[numbers[i]].second;
				}
			}
		}
	}
	return answer;
}
