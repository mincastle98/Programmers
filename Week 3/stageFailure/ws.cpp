#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<double> stage_cnt;
    stage_cnt.assign(N + 2, 0);
    for (int i = 0; i < stages.size(); i++) {
        stage_cnt[stages[i]]++;
    }

    vector<double> tostage_cnt;
    tostage_cnt.assign(N + 2, 0);
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= i; j++) {
            tostage_cnt[i] += stage_cnt[j];
        }
    }

    multimap<double, int, greater<double>> s_f;
    for (int i = 1; i <= N; i++) {
        if (i > 1) {
            if (tostage_cnt[i - 1] == stages.size())
                s_f.insert(pair<double, int>(0, i));
            else
                s_f.insert(pair<double, int>(stage_cnt[i] / (stages.size() - tostage_cnt[i - 1]), i));
        }
        else
            s_f.insert(pair<double, int>(stage_cnt[i] / double(stages.size()), i));
    }

    multimap<double, int>::iterator iter;

    for (iter = s_f.begin(); iter != s_f.end(); iter++) {
        answer.push_back(iter->second);
    }

    return answer;

}