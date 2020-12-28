#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> PQ;
    for (int i = 0; i < scoville.size(); i++)
        PQ.push(scoville[i]);

    while (PQ.top() < K) {
        int first, second;
        if (PQ.size() <= 1) {
            answer = -1;
            return answer;
        }
        first = PQ.top();
        PQ.pop();
        second = PQ.top();
        PQ.pop();
        first = first + second * 2;
        PQ.push(first);
        answer++;
    }

   
    return answer;
}