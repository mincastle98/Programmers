#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
bool cmp(pair<int, double> a, pair<int, double> b) //pair 들의 크기를 비교하는 함수
{
	if (a.second == b.second)
		return a.first < b.first; //pair에서 second의 index가 같다면
//앞의 pair의 first가 더 작은 경우에 true를 return 한다
	return a.second > b.second; //그 외의 경우에는, 앞의 pair의 second값이 더 클 경우에 true를 return
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<int, double>> failure; //실패율을 저장할 배열­
	double player = stages.size(); //플레이어의 수는, vector<int>stages 수의 size와 비슷하다
	for (int i = 0; i < N; i++)
	{
		double count = 0;
		for (int k = 0; k < stages.size(); k++)
		{
			if (i + 1 == stages[k]) //stages[k]에 저장된 값, 즉 i+1 번째 스테이지에 도전 중인 
				//플레이어들의 수를 count++를 통해 집계
				count++;
		}
		if (count == 0)//만약 count가 0이면 실패한 사람이 없다는 거니까, (스테이지, 실패율) pair에
			//(i + 1, 0)을 failure에 넣어줌
			failure.push_back(make_pair(i + 1, 0));
		else//그 외의 경우엔, (스테이지, 실패율)을 저장
			failure.push_back(make_pair(i + 1, count / player));
		player = player - count; //총 풀레이어의 수에서 스테이지 도전중으로 걸러진 사람들을 빼주면서 
		//집계를 진행
	}
	sort(failure.begin(), failure.end(), cmp); //cmp함수를 이용하여 pair의 second값 기준으로 failure를 정렬
	vector<pair<int, double>>::iterator it;
	for (it = failure.begin(); it != failure.end(); it++) //failure의 first값을 순서대로 answer에 넣어줌으로써 
		answer.push_back(it->first);
	return answer;
}
