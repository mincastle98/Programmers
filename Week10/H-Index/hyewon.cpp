#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int cnt = 1;
	sort(citations.begin(), citations.end());

	for (int i = 0; i < citations.size(); i++) {
		int bigger = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= cnt)
				bigger++; //h번 이상 인용된 논문의 개수
		}	
		int smaller = citations.size() - bigger;
		if (bigger >= cnt && smaller < cnt) {
			if (answer < cnt)
				answer = cnt;
		}
		cnt++;
	}
	return answer;
}

int main() {
	cout<< solution({ 0,1,4,5,6 });
}