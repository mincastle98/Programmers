#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> neededDay;
    int day;

    for (int i = 0; i < progresses.size(); i++) {
        float day_ = (float)(100 - progresses[i]) / speeds[i];
        if (!(day_ - (int)day_)) {
            neededDay.push(day_);
        } else
            neededDay.push((int) day_ + 1);
    }

    while (!neededDay.empty()) {
        int tmp = neededDay.front();
        neededDay.pop();
        int cnt = 1;

        while (neededDay.front() <= tmp && !neededDay.empty()) {
            neededDay.pop();
            cnt++;
        }

        answer.push_back(cnt);
    }

    return answer;
}