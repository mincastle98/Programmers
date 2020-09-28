#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
bool cmp(pair<int, double> a, pair<int, double> b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<int, double>> failure; //½ÇÆÐÀ² ÀúÀå ¹è¿­
	double player = stages.size();
	for (int i = 0; i < N; i++)
	{
		double count = 0;
		for (int k = 0; k < stages.size(); k++)
		{
			if (i + 1 == stages[k])
				count++;
		}
		if (count == 0)
			failure.push_back(make_pair(i + 1, 0));
		else
			failure.push_back(make_pair(i + 1, count / player));
		player = player - count;
	}
	sort(failure.begin(), failure.end(), cmp);
	vector<pair<int, double>>::iterator it;
	for (it = failure.begin(); it != failure.end(); it++)
		answer.push_back(it->first);
	return answer;
}
