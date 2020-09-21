#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> students(n, 1); //학생들의 체육복 갯수를 1로 초기화
	for (int i = 0; i < n; i++) //lost 배열에 있는 순서에 해당하는 학생들의 체육복 갯수를 --해 줌
	{
		for (int j = 0; j < lost.size(); j++)
		{
			if ((i + 1) == lost[j])
			{
				students[i]--;
			}
		}
	}

	for (int i = 0; i < n; i++) //reserve 배열에 있는 순서에 해당하는 학생들의 체육복 갯수를 ++해 줌
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if ((i + 1) == reserve[j])
			{
				students[i]++;
			}
		}
	}

	for (int k = n - 1; k > 0; k--) //뒤에 있는 학생이 옷 2벌 ,앞에 있는 학생이 옷 0벌이면 앞에 학생한테 빌려준다
	{
		if ((students[k] == 2) && (students[k - 1] == 0))
		{
			students[k]--;
			students[k - 1]++;
		}
	}

	for (int i = 0; i < students.size() - 1; i++) //앞에 있는 학생이 옷 2 벌, 뒤에 있는 학생이 옷 0벌이면 뒤에 학생한테 빌려준다
	{
		if ((students[i] == 2) && (students[i + 1] == 0))
		{
			students[i]--;
			students[i + 1]++;
		}
	}



	for (int a = 0; a < students.size(); a++) //루프를 돌면서, 배열 값이 0보다 크면 answer++ 시켜준다.
	{
		if (students[a] > 0)
			answer++;
	}

	return answer;
}