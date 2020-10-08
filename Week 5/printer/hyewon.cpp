#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < priorities.size(); i++)
		q.push({ i, priorities[i] });

	sort(priorities.begin(), priorities.end());

	int cnt = 0;
	while (!q.empty()) {
		if (q.front().second != priorities.back()) {
			q.push(q.front());
			q.pop();
		}
		else {
			cnt++;
			if (q.front().first == location) {
				answer = cnt; break;
			}
			else {
				priorities.pop_back(); q.pop();
			}
		}
	}

	return answer;
}