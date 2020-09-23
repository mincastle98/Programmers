#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(double a, double b) {
	return a > b;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> num(N, 0);
	vector<double> failure;
	vector<double> copy;

	double size = stages.size();
	sort(stages.begin(), stages.end(), desc);

	for (int i = 0; i < N; i++) {
		for (int j = stages.size() - 1; j >= 0; j--) {
			if (i + 1 != stages[j]) break;
			else {
				num[i]++;
				stages.pop_back();
			}
		}
	}

	int sum = 0; 
	for (int i = 0; i < N; i++) {
		if (i > 0)
			sum += num[i - 1];
		if (sum != size) { //divded by 0
			double value = (double)num[i] / ((double)size - (double)sum);
			failure.push_back(value);
		}
		else failure.push_back(0);
	}

	copy.assign(failure.begin(), failure.end());
	sort(failure.begin(), failure.end(), desc);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (failure[i] == copy[j]) {
				answer.push_back(j + 1);
				copy[j] = -1;
			}
		}
	}
	return answer;
}
