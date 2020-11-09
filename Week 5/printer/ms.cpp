#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> now;
    priority_queue<int> checkPriority;

    for (int i = 0; i < priorities.size(); i++) {
        now.push(make_pair(i, priorities[i]));
        checkPriority.push(priorities[i]);
    }

    while (!now.empty()) {
        if (now.front().second == checkPriority.top()) {
            if (now.front().first == location) {
                answer++;
                break;
            } else {
                answer++;
                now.pop();
                checkPriority.pop();
            }
        } else {
            now.push(now.front());
            now.pop();
        }
    }

    return answer;
}

int main(void) {
    solution({2, 1, 3, 2}, 2);
    return 0;
}