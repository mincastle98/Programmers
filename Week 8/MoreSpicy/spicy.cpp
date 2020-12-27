#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> test;

	for (int i = 0; i < scoville.size(); i++)
		test.push(scoville[i]);

	while (test.top() < K)
	{
		if (test.size() < 2)
		{
			answer = -1;
			break;
		}
		else
		{

			int first = test.top();
			test.pop();
			int second = test.top();
			test.pop();
			test.push(first + (2 * second));
			answer++;
		}
	}

	return answer;
}
