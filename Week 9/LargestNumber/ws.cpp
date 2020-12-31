#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool large(string x, string y) {
    return x + y > y + x;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> num;
    for (int i = 0; i < numbers.size(); i++) {
        num.push_back(to_string(numbers[i]));
    }

    sort(num.begin(), num.end(), large);

    if (num[0] == "0")
        answer = "0";
    else {
        for (int i = 0; i < num.size(); i++)
            answer += num[i];
    }

    return answer;
}