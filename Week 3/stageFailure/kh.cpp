#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;



vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double>fail;
    double player = stages.size();

    for (int i = 1; i <= N; i++) {
        double count = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] == i)
                count++;
        }
        if (count == 0)
            fail.push_back(0);
        else
            fail.push_back(count / player);
        player -= count;
    }

    for (int i = 0; i < N; i++) {
        auto iter = max_element(fail.begin(), fail.end());
        answer.push_back(iter - fail.begin() + 1);
        *iter = -120;
    }
    return answer;
    
}

int main() {
    int N = 5;
    vector<int>answer;
    vector<int>stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    answer = solution(N, stages);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    
}