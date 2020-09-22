#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int temp=0;
    int cnt = 0;
    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++) {
        temp += d[i];
        cnt++;
        if (temp > budget) {
            cnt = cnt - 1;
            break;
        }
        else if (temp == budget)
            break;
    }
   
    answer = cnt;;
    return answer;
}

int main() {
    vector<int>d = { 2,2,3,3 };
    int budget = 10;
    cout << solution(d, budget) << endl;
}