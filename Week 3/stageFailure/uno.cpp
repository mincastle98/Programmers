#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	vector<pair<int, double>> fR;
	
	for (int i = 1; i <= N; i++) {
		int son = 0, parents = 0, cnt = 0;
		for (int t : stages) {
			if (t >= i)
				parents++; // 스테이지 도달
			else
				cnt++; // 스테이지 도달 X
			if (t == i)
				son++; // 스테이지 클리어 X
		}
		if (cnt == stages.size())
			fR.push_back(make_pair(i, 0));
		else
            fR.push_back(make_pair(i, son/(double)parents));
	}
	sort(fR.begin(), fR.end(), cmp);

	for (int i = 0; i < N; i++)
		answer.push_back(fR[i].first);
		
	return answer;
}