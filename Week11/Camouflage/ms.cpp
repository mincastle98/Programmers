#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<string> &a, vector<string> &b) {
    return a[1] > b[1];
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<pair<string, int>> type;

    sort(clothes.begin(), clothes.end(), compare);
    for (int i = 0; i < clothes.size(); i++) {
        if (type.empty()) type.push_back(make_pair(clothes[i][1], 1));
        else {
            if (type.back().first == clothes[i][1]) type.back().second++;
            else type.push_back(make_pair(clothes[i][1], 1));
        }
    }

    for (int i = 0; i < type.size(); i++) {
        answer *= type[i].second + 1;
    }

    return answer - 1;
}