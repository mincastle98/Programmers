#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());

	while (!people.empty()) {
		int weight = 0;

		weight += people[0];
		people.erase(people.begin());

		for (int i = people.size() - 1; i >= 0; i--) {
			if (people[i] <= limit - weight) {
				weight += people[i];
				people.erase(people.begin() + i);
				i--;
			}
			if (limit - weight < people[0])
				break;
		}
		answer++;
	}

	return answer;
}

int main() {
	vector<int> people = { 70,50,80,50 };
	int limit = 100;

	cout << solution(people, limit)<<endl;
}