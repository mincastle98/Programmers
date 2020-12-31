#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

int solution(vector<int> nums) {
	int answer = 0;
	vector<int> sum;
	int n, a, b, c;

	for (int i = 0; i < nums.size(); i++) {
		a= nums[i];
		for (int j = 1; j < nums.size(); j++) {
			if (i == j)
				continue;
			b= nums[j];
			for (int k = 2; k < nums.size(); k++) {
				if (i==k||k == j)
					continue;
				c= nums[k];
				n = a + b + c;
				int flag = 0;
				for (int l = 0; l < sum.size(); l++) {
					if (n == sum[l])
						flag = 1;
				}
				if (flag == 0) 
					sum.push_back(n);
			}
		}
	}

	for (int i = 0; i < sum.size(); i++) {
		//cout << sum[i] << endl;
		if (isPrime(sum[i]))
			answer++;
	}

	return answer;
}

int main() {
	vector <int> nums = { 1,2,7,6,4 };

	cout<<solution(nums)<<endl;
}