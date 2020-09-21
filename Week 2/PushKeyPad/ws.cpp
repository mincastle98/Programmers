#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 12;


    for (int i = 0; i < numbers.size(); i++) {
        int num;
        if (numbers[i] == 0)
            num = 11;
        else
            num = numbers[i];

        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            left = numbers[i];
        }

        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            right = numbers[i];
        }

        else {
            int countr = 0;
            if (abs(num - right) % 3 == 0)
                countr = abs(num - right) / 3;
            else
                countr = 1 + abs(num - right + 1) / 3;

            int countl = 0;
            if (abs(num - left) % 3 == 0)
                countl = abs(num - left) / 3;
            else
                countl = 1 + abs(num - left - 1) / 3;

            if (countl > countr) {
                answer += "R";
                right = num;
            }
            else if (countl < countr) {
                answer += "L";
                left = num;
            }
            else {
                answer += toupper(hand[0]);
                if (hand == "left")
                    left = num;
                else
                    right = num;
            }
        }

    }
    return answer;
}