#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> time;
    for (int i = 0; i < progresses.size(); i++) {
        if ((100 - progresses[i]) % speeds[i] == 0)
            time.push_back((100 - progresses[i]) / speeds[i]);
        else
            time.push_back((100 - progresses[i]) / speeds[i] + 1);
    }
    int max = time[0];
    int cnt = 0;
    for (int i = 0; i < time.size(); i++) {
        if (max >= time[i])
            cnt++;
        else {
            max = time[i];
            answer.push_back(cnt);
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}