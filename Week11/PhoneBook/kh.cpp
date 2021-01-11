#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(const string& s1, const string& s2) {

    if (s1.size() == s2.size()) 
        return s1 < s2;
    return s1.size() < s2.size(); 
}


bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end(), comp);

    string check = phone_book[0];
    int len = check.length();

    for (int i = 0; i < phone_book.size(); i++) {
        phone_book[i].substr(0, len);
    }
    for (int i = 0; i < phone_book.size(); i++) {
        if (check==phone_book[i]) {
            answer = false;
            break;
        }
        else continue;
    }
    return answer;
}


int main() {
    vector<string>phone_book = { "123", "789", "456" };
    sort(phone_book.begin(), phone_book.end(),comp);
    for (int i = 0; i < phone_book.size(); i++) {
        cout << phone_book[i] << endl;
    }
    cout<<solution(phone_book);

}
