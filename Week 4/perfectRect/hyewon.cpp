#include <math.h>

using namespace std;

long long solution(int w, int h) {
	long long answer = 0;

	for (int i = 1; i < w; i++) {
		answer += floor((double)-h / w * i + h); //³»¸²
	}
	answer *= 2; //for rectangle
	return answer;
}
