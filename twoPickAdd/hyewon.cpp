#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	vector<int> copy;
	int sum, turn, cnt = 0;
	turn = (numbers.size()*(numbers.size() - 1) / 2) + numbers.size() - 1;

	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < turn; i++) {
		if (cnt == numbers.size() - 1) {
			numbers.pop_back();
			cnt = 0; continue;
		}
		sum = (numbers.back()) + (numbers[numbers.size() - 2 - cnt]);
		cnt++;

		answer.push_back(sum);
	}

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end()); //중복 제거


	return answer;
}

int main() {
	vector<int> numbers1 = { 2, 1, 3, 4, 1 };
	vector<int> numbers2 = { 5, 0, 2, 7 };

	vector<int> result1 = solution(numbers1);
	vector<int> result2 = solution(numbers2);

	for (int i = 0; i < result1.size(); i++) {
		cout << result1[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < result2.size(); i++) {
		cout << result2[i] << ' ';
	}
	cout << endl;
}