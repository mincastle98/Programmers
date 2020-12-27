#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);

	while (1) {
		int mix = 0;
		if (pq.top() < K) {
			mix += pq.top(); pq.pop();
			mix += 2 * pq.top(); pq.pop();
			pq.push(mix); answer++;
			if (pq.size() == 1) {
				if (pq.top() < K) return -1;
				else return answer;
			}
		}
		else return answer;
	}
	if (answer == 0) return -1;
	else return answer;
}

int main() {
	vector<int> s = { 1,2,3,9,10,12 };
	cout << solution(s, 7) << endl;
}