#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}
string solution(vector<int> numbers) {
	string answer;
	vector<string> temp;

	for (int i : numbers) {
		temp.push_back(to_string(i));
	}

	sort(temp.begin(), temp.end(), cmp);

	if (temp[0] == "0") {
		answer += '0';
		return answer;
	}
	for (string s : temp) {
		answer += s;
	}

	return answer;
}