#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool desc(string i, string j) {
	return i+j > j+i; 
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> arr;
	for (int i = 0; i < numbers.size(); i++) {
		arr.push_back(to_string(numbers[i]));
	}
	sort(arr.begin(), arr.end(), desc);

	for (int i = 0; i < arr.size(); i++) {
		answer += arr[i];
	}
	
	if (arr[0] == "0") answer ="0";
	return answer;
}

int main() {
	vector<int> n1 = { 0, 0, 0 };
	vector<int> n2 = { 3,30,34,5,9 };
	cout << solution(n1) << endl;
	cout << solution(n2) << endl;
}