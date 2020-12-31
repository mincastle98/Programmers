#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> nums) {
    int answer = -1;
    vector<int> sums;
    int primeNum[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for(int i = 0; i < nums.size(); i++) {
        for(int j = i; j < nums.size(); j++) {
            for(int k = j; k < nums.size(); k++) {
                if (i == j) break;
                if (i == k || j == k) continue;
                sums.push_back(nums[i] + nums[j] + nums[k]);
            }
        }
    }

    for (int i : primeNum) {
        for (int j = 0; j < sums.size(); j++) {
            if (sums[j] % i == 0 && sums[j] / i != 1) {
                cout << sums[j] << endl;
                sums.erase(sums.begin() + j);
                j--;
            }
        }
    }

    answer = sums.size();

    return answer;
}
