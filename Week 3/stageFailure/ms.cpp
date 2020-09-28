// stageFailure
// Created by 김민성 on 2020/09/28.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, float> &a, const pair<int, float> &b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> user(N + 1, 0);
    vector<pair<int, float>> failure(N);
    int totalUser = stages.size();

    for (int i :stages) {
        user[i - 1]++;
    }

    for (int i = 0; i < user.size() - 1; i++) {
        if (totalUser > 0)
            failure[i] = make_pair(i + 1, (float) user[i] / totalUser);
        else failure[i] = make_pair(i + 1, 0);
        totalUser -= user[i];
    }

    sort(failure.begin(), failure.end(), compare);

    for (int i = 0; i < failure.size(); i++) {
        answer.push_back(failure[i].first);
    }

    return answer;
}