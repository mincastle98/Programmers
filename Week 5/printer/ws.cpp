#include <string>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    while (1) {
        bool isMax = true;
        for (int i = 1; i < priorities.size(); i++) {
            if (priorities[0] < priorities[i]) {
                isMax = false;
                priorities.push_back(priorities[0]);
                priorities.erase(priorities.begin());
                break;
            }
        }
        if (isMax == true) {
            if (location == 0) {
                answer++;
                return answer;
            }
            priorities.erase(priorities.begin());
            answer++;
        }
        if (location == 0)
            location = priorities.size() - 1;
        else
            location--;
    }
    return answer;
}