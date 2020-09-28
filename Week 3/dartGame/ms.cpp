// dartGame
// Created by 김민성 on 2020/09/28.
//
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    vector<int> isGetStar;
    vector<int> isGetSharp;

    int tmp = 0;
    int cnt = 0;
    for (char i :dartResult) {
        if (isdigit(i)) {
            if (tmp != 0) tmp = 10;
            else tmp = i - '0';
            cnt++;
        } else if (isalpha(i)) {
            switch (i) {
                case 'D':
                    tmp = pow(tmp, 2);
                    break;
                case 'T':
                    tmp = pow(tmp, 3);
                    break;
            }
            score.push_back(tmp);
            tmp = 0;
        } else {
            if (i == '*') {
                if (score.size() >= 2) score[score.size() - 2] *= 2;
                score.back() *= 2;
            } else score.back() *= -1;
        }
    }

    for (int i :score)
        answer += i;

    return answer;
}