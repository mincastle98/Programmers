// secretMap
// Created by 김민성 on 2020/09/28.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    vector<vector<int>> map1(n), map2(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr1[i] >> j & 1) map1[i].push_back(1);
            else map1[i].push_back(0);
            if (arr2[i] >> j & 1) map2[i].push_back(1);
            else map2[i].push_back(0);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map1[i][j] == 1 || map2[i][j] == 1)
                answer[i] += '#';
            else answer[i] += ' ';
        }
        reverse(answer[i].begin(), answer[i].end());
    }

    return answer;
}