#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reverse) {
	int answer = 0;
	map<int, int> getCloth;

	for (int i = 1; i <= n; i++) {
		getCloth.insert(make_pair(i, 1));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < lost.size(); j++) {
			if (i == lost[j])
				getCloth[i]--;
		}
		for (int k = 0; k < reverse.size(); k++) {
			if (i == reverse[k])
				getCloth[i]++;
		}
	}

	for (int i = 1; i <= getCloth.size(); i++) {
		if (getCloth[i] == 0) {
			if (i > 1 && getCloth[i - 1] > 1) {
				getCloth[i - 1]--;
				getCloth[i]++;
			}
			else if (i < n && getCloth[i + 1] > 1) {
				getCloth[i + 1]--;
				getCloth[i]++;
			}
		}
	}

	for (int i = 0; i < getCloth.size(); i++) {
		if (getCloth[i] > 0) answer++;
	}
	return answer;
}

int main() {
	int n1 = 5, n2 = 5, n3 = 3;
	vector<int> l1 = { 2, 4 }, l2 = { 2, 4 }, l3 = { 3 };
	vector<int> r1 = { 1, 3, 5 }, r2 = { 3 }, r3 = { 1 };

	cout << solution(n1, l1, r1) << endl;
	cout << solution(n2, l2, r2) << endl;
	cout << solution(n3, l3, r3) << endl;
}