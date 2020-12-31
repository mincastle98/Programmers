#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> nums) {
    int answer = -1;
    vector<int> sums;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                sums.push_back(nums[i] + nums[j] + nums[k]);
            }
        }
    }

    for (int i : sums) {
        int flag = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) answer++;
    }

    if (answer != -1) answer++;

    return answer;
}
