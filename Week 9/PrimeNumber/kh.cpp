#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int sum) { 
    for (int i = 2; i <= sqrt(sum); i++) {
        if ((sum % i) == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums) {

	int answer = 0;

	for (int i = 0; i <= nums.size() - 3; i++) {
		for (int j = i + 1; j <= nums.size() - 2; j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				if (isPrime(nums[i] + nums[j] + nums[k]))
					answer++;
			}
		}
	}
	return answer;
}