#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    int temp = 0;
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                lost[i] = 102;
                reserve[j] = 104;
            }
        }
    }
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] + 1 == reserve[j] && lost[i] - 1 != reserve[j]) {
                lost[i] = 102;
                reserve[j] = 104;
            }
            else if (lost[i] + 1 != reserve[j] && lost[i] - 1 == reserve[j]) {
                lost[i] = 102;
                reserve[j] = 104;
            }
        }
    }
    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == 102)
            temp++;
    }
    answer = answer + temp;
    return answer;
}

int main() {
    int n = 30;
    vector<int>lost = {28,29,30};
    vector<int>reserve = {30};
    int answer = solution(n, lost, reserve);
    
    cout << answer << endl;
}