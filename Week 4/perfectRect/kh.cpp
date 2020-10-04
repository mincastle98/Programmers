#include<iostream>
#include<cmath>
using namespace std;

long long gcd(long w, long h) {
    long small, big;
    big = w >= h ? w : h;
    small = w < h ? w : h;

    while (small != 0) {
        long temp = big % small;
        big = small;
        small = temp;
    }
    return big;
}

long long solution(int w, int h) {
    long long answer = 1;
    long long all_rec = (long long)w * (long long)h;
   
    answer = all_rec - ((long long)w + (long long)h - gcd(w, h));
    return answer;
}
