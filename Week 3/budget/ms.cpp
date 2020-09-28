// Budget
// Created by 김민성 on 2020/09/28.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());

    int tmp = 0;
    int cnt;
    for (cnt = 0; cnt < d.size(); cnt++) {
        if (tmp <= budget) {
            tmp += d[cnt];
            if (tmp > budget) {
                tmp -= d[cnt];
                break;
            }
        } else break;
    }

    answer = cnt;
    return answer;
}