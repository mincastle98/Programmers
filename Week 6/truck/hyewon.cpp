#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1;
	int sumOfWeight = 0;
	queue<int> q;
	vector<int> stayTime;

	int size = truck_weights.size();
	reverse(truck_weights.begin(), truck_weights.end());

	while (1) {
		answer++;
		if (truck_weights.size() != 0 && sumOfWeight + truck_weights.back() <= weight) {
			q.push(truck_weights.back());
			stayTime.push_back(0);
			sumOfWeight += truck_weights.back();
			truck_weights.pop_back();
		}
		if (!q.empty()) {
			for (int i = 0; i < stayTime.size(); i++) {
				stayTime[i]++;
			}
			if (stayTime[0] == bridge_length) {
				stayTime.erase(stayTime.begin());
				sumOfWeight -= q.front();
				q.pop();
			}
		}
		if (q.size() == 0 && truck_weights.size() == 0) break;
	}

	return answer;
}

int main() {
	cout << solution(2, 10, { 7, 4, 5, 6 }) << endl;
	cout << solution(100, 100, { 100 }) << endl;
	cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << endl;
}