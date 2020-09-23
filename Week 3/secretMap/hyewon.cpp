#include <string>
#include <vector>

using namespace std;

string convert2binary(int n, int num) {
	int mask;
	string result = "";
	for (int i = n - 1; i >= 0; i--) {
		mask = 1 << i;
		if ((num & mask) == mask) result += "1";
		else result += "0";
	}
	return result;
}

string compare(char a, char b) {
	if (a == '1' || b == '1') 
		return "1";
	else
		return "0";
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<string> a1, a2;
	for (int i = 0; i < n; i++) {
		a1.push_back(convert2binary(n, arr1[i]));
		a2.push_back(convert2binary(n, arr2[i]));
	}

	for (int i = 0; i < n; i++) {
		string line = "";
		for (int j = 0; j < n; j++) {
				line += compare(a1[i][j], a2[i][j]);
		}
		answer.push_back(line);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (answer[i][j] == '0') answer[i][j] = ' ';
			else answer[i][j] = '#';
		}
	}
	return answer;
}