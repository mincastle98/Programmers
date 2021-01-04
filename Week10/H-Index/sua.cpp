#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	
	int mid= citations.size() / 2-1;

	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] >= mid)
			answer++;
	}

	return answer;
}

int main() {
	vector<int> citations = { 3, 0, 6, 1, 5 };
	cout << solution(citations) << endl;
}