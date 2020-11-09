#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> pre_skill;

    for (char i : skill) {
        pre_skill.push_back(i);
    }

    reverse(pre_skill.begin(), pre_skill.end());

    for (string i : skill_trees) {
        vector<char> temp = pre_skill;
        bool isPossible = true;

        for (char j : i) {
            if (find(pre_skill.begin(), pre_skill.end(), j) != pre_skill.end()) {
                if (j == temp.back())
                    temp.pop_back();
                else {
                    isPossible = false;
                    break;
                }
            }
        }
        if (isPossible) answer++;
    }

    return answer;
}