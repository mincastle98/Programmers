#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
/*
int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(), scoville.end());
    int min = scoville[0];

    while (min < K) {
        scoville[0] = scoville[0] + scoville[1] * 2;
        scoville.erase(scoville.begin() + 1);
        sort(scoville.begin(), scoville.end());
        min = scoville[0];
        answer++;
        if (scoville.size() == 1 && min < K) {
            answer = -1;
            break;
        }
    }
    return answer;
}
*/

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    int min = pq.top();
    

    while (min < K) {
        pq.pop();
        min = min + pq.top() * 2;
        pq.pop();
        pq.push(min);
        min = pq.top();
        answer++;
        if (pq.size() == 1 && min < K) {
            answer = -1;
            break;
        }
    }
    return answer;
}
