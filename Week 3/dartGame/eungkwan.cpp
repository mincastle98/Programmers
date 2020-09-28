#include <string>
#include <stack> //stack을 사용하기 위해
#include <cctype> //isdigit()함수를 사용하기 위해
using namespace std;

int solution(string dartResult) {
	int len = dartResult.length(); //string의 길이
	int answer = 0;
	int tmp = 0; //알파벳 뒤에 *가 나올 때, 그 전의 값을 저장하기 위해 사용
	int arr[3]; // 숫자, 보너스, 옵션 => 한 주기가 끝날 때마다 거기서 나온 값을 스택에 저장하는데, 나중에 그 작업이 끝나면 여기에 있는 값을 arr[3]에 저장
	//3으로 정한이유는 다트 게임 횟수가 max = 3이기 때문이고, 이걸 굳이 배열에 저장하는 이유는 마지막에 덧셈작업을 간단히 해주기 위함이다.
	stack<int> s; //값을 저장하기 위한 stack
	for (int i = 0; i < len; i++)
	{
		if ((dartResult[i] == 'D') && (dartResult[i + 1] == '#')) //알파벳 + 뒤에 샵이 붙을 때 3가지 경우
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
				s.push(-100);
			else
				s.push((dartResult[i - 1] - '0') * (dartResult[i - 1] - '0') * -1); //숫자가 10 아닐 
		}
		else if ((dartResult[i] == 'T') && (dartResult[i + 1] == '#'))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
				s.push(-1000);
			else
				s.push((dartResult[i - 1] - '0') * (dartResult[i - 1] - '0') * (dartResult[i - 1] - '0') * -1); //그 외
		}
		else if ((dartResult[i] == 'S') && (dartResult[i + 1] == '#'))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
				s.push(-10);
			else
				s.push((dartResult[i - 1] - '0') * -1); //그 외
		}
		else if ((dartResult[i] == 'D') && (dartResult[i + 1] == '*'))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
			{
				tmp = s.top();
				s.pop();
				s.push(2 * tmp);
				s.push(200);
			}
			else
			{
				tmp = s.top();
				s.pop();
				s.push(2 * tmp);
				s.push((dartResult[i - 1] - '0') * (dartResult[i - 1] - '0') * 2);
			}
		}
		else if ((dartResult[i] == 'T') && (dartResult[i + 1] == '*'))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
			{
				tmp = s.top();
				s.pop();
				s.push(2 * tmp);
				s.push(2000);
			}
			else
			{
				tmp = s.top();
				s.pop();
				s.push(2 * tmp);
				s.push((dartResult[i - 1] - '0') * (dartResult[i - 1] - '0') * (dartResult[i - 1] - '0') * 2);
			}
		}
		else if ((dartResult[i] == 'S') && (dartResult[i + 1] == '*'))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
			{
				tmp = s.top();
				s.pop();
				s.push(2 * tmp);
				s.push(20);
			}
			else
			{
				tmp = s.top();
				s.pop();
				s.push(2 * tmp);
				s.push((dartResult[i - 1] - '0') * 2);
			}
		}
		else if ((dartResult[i] == 'D') && (isdigit(dartResult[i + 1]) == 1))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
				s.push(100);
			else
				s.push((dartResult[i - 1] - '0') * (dartResult[i - 1] - '0')); //그 외
		}
		else if ((dartResult[i] == 'T') && (isdigit(dartResult[i + 1]) == 1))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
				s.push(1000);
			else
				s.push((dartResult[i - 1] - '0') * (dartResult[i - 1] - '0') * (dartResult[i - 1] - '0')); //그 외
		}
		else if ((dartResult[i] == 'S') && (isdigit(dartResult[i + 1]) == 1))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
				s.push(10);
			else
				s.push((dartResult[i - 1] - '0')); //그 외
		}
		else if ((dartResult[i] == 'D') && (i == len - 1))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
				s.push(100);
			else
				s.push((dartResult[i - 1] - '0') * (dartResult[i - 1] - '0')); //그 외
		}
		else if ((dartResult[i] == 'T') && (i == len - 1))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
				s.push(1000);
			else
				s.push((dartResult[i - 1] - '0') * (dartResult[i - 1] - '0') * (dartResult[i - 1] - '0')); //그 외
		}
		else if ((dartResult[i] == 'S') && (i == len - 1))
		{
			if ((dartResult[i - 1] == '0') && (dartResult[i - 2] == '1')) //10일 때
				s.push(10);
			else
				s.push((dartResult[i - 1] - '0')); //그 외
		}
	}
	for (int k = 0; k < 3; k++)
		arr[k] = NULL;//배열 초기화
	for (int k = 0; k < 3; k++)
	{
		arr[k] = s.top();
		s.pop(); //stack
	}
	for (int k = 0; k < 3; k++)
		answer += arr[k];
	return answer;
}
