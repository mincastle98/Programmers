#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(int n) {
    string answer = "";
    int digit;
    if (n <= 193710243) {
        for (int i = 0;; i++) {
            if ((double)3 / 2 * (pow(3, i) - 1) < n && n <= (double)3 / 2 * (pow(3, i + 1) - 1)) {
                digit = i + 1;
                break;
            }
        }
    }
    else {
        digit = 17;
        for (int i = 17;; i++) {
            if ((double)3 / 2 * (pow(3, i) - 1) < n && n <= (double)3 / 2 * (pow(3, i + 1) - 1)) {
                digit = i + 1;
                break;
            }
        }
    }

    for (int i = digit - 1; i >= 0; i--) {
        if (n <= ((double)3 / 2 * (pow(3, i) - 1)) + pow(3, i)) {
            answer += "1";
            n -= pow(3, i);
        }
        else if (n <= ((double)3 / 2 * (pow(3, i) - 1)) + 2 * pow(3, i)) {
            answer += "2";
            n -= 2 * pow(3, i);
        }
        else {
            answer += "4";
            n -= 3 * pow(3, i);
        }
    }

    return answer;
}