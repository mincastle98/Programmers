// fakeExam
// Created by 김민성 on 2020/09/10.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);
    int ans1[5] = {1, 2, 3, 4, 5};
    int ans2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int ans3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == ans1[i % 5]) score[0]++;
        if (answers[i] == ans2[i % 8]) score[1]++;
        if (answers[i] == ans3[i % 10]) score[2]++;
    }

    int max_score = *max_element(score.begin(), score.end());

    for (int i = 0; i < score.size(); i++) {
        if (score[i] == max_score) answer.push_back(i + 1);;
    }

    return answer;
}

int main() {
    vector<int> answers = {1, 2, 3, 4, 5};

    solution(answers);

    return 0;
}