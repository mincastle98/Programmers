#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> nums;
    for (int i : numbers)
        nums.push_back(to_string(i));

    sort(nums.begin(), nums.end(), compare);

    for (string i : nums) {
        answer += i;
    }
    if(answer[0] == '0') answer = "0";

    return answer;
}