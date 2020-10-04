#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int cnt = 0;
    for (int i = 0; i < prices.size(); i++) {
        cnt = 0;
        if (i == prices.size() - 1)
            answer.push_back(0);
        else {
        for (int j = i; j < prices.size(); j++) {
            cnt++;
            if (prices[i] <= prices[j]) continue;
            else {
                break;
            }
        }
        answer.push_back(cnt - 1);
    }
}
    return answer;
}

int main() {
    vector<int>prices = { 1,2,3,2,3 };
    vector<int>answer = solution(prices);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

}
