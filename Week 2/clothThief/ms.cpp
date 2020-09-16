// clothThief
// Created by 김민성 on 2020/09/14.

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> cloth(n, 1);

    for (int i:lost)
        cloth[i - 1]--;
    for (int i:reserve)
        cloth[i - 1]++;

    for (int i = 0; i < n; i++) {
        if (cloth[i] == 0) {
            if (i >= 1 && cloth[i - 1] > 1) {
                cloth[i - 1]--;
                cloth[i]++;
            } else if (i < n - 1 && cloth[i + 1] > 1) {
                cloth[i + 1]--;
                cloth[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (cloth[i] == 0) answer--;
    }

    return answer;
}