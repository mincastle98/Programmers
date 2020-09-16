// Watermelonwater
// Created by 김민성 on 2020/09/10.

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for (int i = 0; i < n; i++) {
        if (i & 1) answer += "박";
        else
            answer += "수";
    }

    return answer;
}

int main() {
    solution(3);

    return 0;
}