#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> cnt(3);

	vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<int> v2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> v3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	for (int i = 0; i < answers.size(); i++) {
		if (v1[i%v1.size()] == answers[i]) cnt[0]++;
		if (v2[i%v2.size()] == answers[i]) cnt[1]++;
		if (v3[i%v3.size()] == answers[i]) cnt[2]++;
	}

	int max = 0;
	for (int i = 0; i < cnt.size(); i++) {
		if (max < cnt[i])
			max = cnt[i];
	}

	for (int i = 0; i < cnt.size(); i++) {
		if (cnt[i] == max)
			answer.push_back(i + 1);
	}
	return answer;
}

int main() {
	vector<int> a = { 1, 3, 2,4,2 };
	vector<int> answer;

	solution(a);
	answer = solution(a);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
}
