// Marathon
// Created by 김민성 on 2020/09/10.

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> participant_;

    for (int i = 0; i < participant.size(); i++) {
        if (participant_.find(participant[i]) == participant_.end())
            participant_.insert(make_pair(participant[i], 1));
        else participant_[participant[i]]++;
    }

    for (int i = 0; i < completion.size(); i++) {
        if (participant_[completion[i]] == 0) return completion[i];
        else participant_[completion[i]]--;
    }

    for (auto pair:participant_) {
        if (pair.second > 0) answer = pair.first;
    }

    return answer;
}

int main() {
    vector<string> participant = //{"leo", "kiki", "eden"};
            //{"marina", "josipa", "nikola", "vinko", "filipa"};
            {"mislav", "stanko", "mislav", "ana"};
    vector<string> completion = //{"leo", "kiki"};
            //{"josipa", "filipa", "marina", "nikola"};
            {"stanko", "ana", "mislav"};

    solution(participant, completion);

    return 0;
}