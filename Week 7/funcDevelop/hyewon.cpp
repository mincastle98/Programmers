#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q; 
	int flag = 0;

	for (int i = 0; i < progresses.size(); i++) {
		double days = (double)(100 - progresses[i]) / (double)speeds[i];
		q.push(ceil(days));
	}

	while (!q.empty()) {
		int return_value = 1;
		int cmp = q.front();
		q.pop();
		if (q.empty()) { //last element can be poped
			answer.push_back(return_value); 
			break;
		}
		while (cmp >= q.front()) {
			q.pop();
			if (q.empty()) {
				return_value++;
				answer.push_back(return_value);
				flag = 1; 
				break;
			}
			return_value++;
		}
		if (flag == 1) break;
		answer.push_back(return_value);
	}


	return answer;
}