#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i : scoville)
        pq.push(i);

    while(1) {
        if(pq.size() == 1) {
            if (pq.top() < K) return -1;
            else break;
        }

        int tmp = pq.top();
        pq.pop();
        if(tmp < K) {
            int tmp_ = pq.top();
            pq.pop();
            pq.push(tmp + tmp_ * 2);
            answer++;
        } else break;
    }

    return answer;
}