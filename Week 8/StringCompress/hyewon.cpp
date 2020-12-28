#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = 0;
	for (int i = 1; i <= s.length(); i++) {
		string compressed = "";
		string cmp = s.substr(0, i);
		int num = 1;
		if (i == s.length()) compressed = s;
		for (int j = i; j < s.length(); j+=i) {
			if (cmp == s.substr(j, i)) {
				num++;
				if (j == s.length() - i) {
					if (num != 1) compressed += to_string(num);
					compressed += cmp;
				}
			}
			else {
				if (num != 1) compressed += to_string(num);
				compressed += cmp;
				num = 1;
				cmp = s.substr(j, i);
				if (j == s.length() - i) {
					if(num != 1) compressed += to_string(num);
					compressed += cmp;
				}
			}

			if (j + i > s.length()) {
				if (num != 1) compressed += to_string(num);
				compressed += cmp;
			}
		}
		if (answer == 0 && i == 1) answer = compressed.length();
		else if (answer > compressed.length())
			answer = compressed.length();
		
	}

	return answer;
}