// perfectRect
// Created by 김민성 on 2020/10/04.
//
using namespace std;

int getGCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w, int h) {
    long long answer = 1;
    int gcd = getGCD(w, h);
    int w_ = w / gcd;
    int h_ = h / gcd;
    int temp = w_ + h_ - 1;
    answer = (long long)w * h - temp * gcd;

    return answer;
}