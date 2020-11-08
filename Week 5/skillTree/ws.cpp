#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        bool isPoss = true;
        for (int j = 0; j < skill.length() - 1; j++) {
            if (skill_trees[i].find(skill[j]) > skill_trees[i].find(skill[j + 1])) {
                isPoss = false;
                break;
            }
        }
        if (isPoss == true)
            answer++;
    }

    return answer;
}