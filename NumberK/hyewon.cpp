#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {
		vector<int> split;

		for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
			split.push_back(array[j]);
		}
		sort(split.begin(), split.end());
		answer.push_back(split[commands[i][2]-1]);
	}

	return answer;
}

int main() {
	vector<int> arr = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> c = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };

	vector<int> result = solution(arr, c);

	for (int i = 0; i < result.size(); i++) 
		cout << result[i] << ' ';
}