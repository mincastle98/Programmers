#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = s.length();
    string s2;

    for (int i = 1; i <= s.length()/2; i++) {
        vector<string> v;
        int plus = 0;

        int i2;
        if (s.length() % i == 0)
            i2 = s.length() / i;
        else
            i2 = s.length() / i + 1;

        for (int j = 0; j < i2; j++) {
            v.push_back(s.substr(i * j, i));
        }
        int num = 1;
        int k;
        for (k = 0; k < v.size() - 1; k++) {
            if (v[k] == v[k + 1])
                num++;
            else {
                if (num == 1)
                    s2 += v[k];
                else {
                    while (num / 10 > 0) {
                        plus++;
                        num /= 10;
                    }

                    s2 += num;
                    s2 += v[k];
                    num = 1;
                }
            }
        }
        if (num == 1)
            s2 += v[k];
        else {
            while (num / 10 > 0) {
                plus++;
                num /= 10;
            }

            s2 += num;
            s2 += v[k];
        }
        if (s2.length()+ plus < answer)
            answer = s2.length() + plus;

        s2 = "";
    }

    return answer;
}

int main() {
    string s = "zxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    cout << solution(s);
}