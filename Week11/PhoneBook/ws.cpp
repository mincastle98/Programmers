#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    if (a.length() <= b.length())
        return a < b;
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end(), comp);

    for (int i = 0; i < phone_book.size() - 1; i++) {
        for (int j = i + 1; j < phone_book.size(); j++) {
            int flag = 0;
            for (int k = 0; k < phone_book[i].length(); k++) {
                if (phone_book[i][k] != phone_book[j][k])
                    flag = 1;
            }
            if (flag == 0) {
                answer = false;
                break;
            }
        }
        if (answer == false)
            break;
    }
    return answer;
}