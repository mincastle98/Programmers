#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert0to4(string num, int i) {
	num[i] = '4';
	if (num[i - 1] == '0') {
		num = convert0to4(num, i - 1);
	}
	if (num[i - 1] == '4') 
		num[i - 1] = '2';
	else if (num[i - 1] == '2') num[i - 1] = '1';
	else if (num[i - 1] == '1') num[i - 1] = '0';

	return num;
}
string solution(int n) {
	string answer = "";

	while (n != 0) { //converting
		int remainder = n % 3;
		answer = to_string(remainder) + answer;
		n /= 3;
	}

	for (int i = answer.length() - 1; i >= 0; i--) {
		if (answer[i] == '0') {
			if (i != 0) {
				answer = convert0to4(answer, i);
			}
		}
	}
	
	if (answer[0] == '0') answer.erase(answer.begin());

	return answer;
}

int main() {
	cout << solution(9) << endl;
	cout << solution(18) << endl;
	cout << solution(19) << endl;
}