#include <string>
#include <vector>
#include <cctype> //for isdigit(int c)
#include <math.h>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector<int> score;
	int idx = -1;

	for (int i = 0; i < dartResult.size(); i++) {
		if (isdigit(dartResult[i])) {
			idx++;
			if (i > 0 && dartResult[i - 1] == '1' && dartResult[i] == '0') {
				score[idx - 1] *= 10; idx--;
			}
			else {
				score.push_back(dartResult[i] - '0'); //char to int
			}
		}
		else if (isalpha(dartResult[i])) {
			if (dartResult[i] == 'S') {}
			else if (dartResult[i] == 'D') {
				score[idx] = pow(score[idx], 2);
			}
			else if (dartResult[i] == 'T') {
				score[idx] = pow(score[idx], 3);
			}
		}
		else {
			if (dartResult[i] == '*') {
				if (score.size() == 0)
					score[idx] *= 2;
				else {
					score[idx - 1] *= 2;
					score[idx] *= 2;
				}
			}
			else if (dartResult[i] == '#') {
				score[idx] *= -1;
			}
		}
	}

	for (int i = 0; i < 3; i++) answer += score[i];
	return answer;
}