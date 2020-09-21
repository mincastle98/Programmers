#include <string>
#include <vector>

using namespace std;

int getDistance(int src, int dst) {
    int sum = 0;
    int s = src, d = dst;
    if (s == 0)
        s = 11;
    if (d == 0)
        d = 11;
    if (s > d + 1) {
        while (s > d + 1) {
            sum++;
            s -= 3;
        }
    }
    else if (d - 1 > s) {
        while (d - 1 > s) {
            sum++;
            s += 3;
        }
    }

    sum += abs(s - d);
    return sum;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int position_l = 10;
    int position_r = 12;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            position_l = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            position_r = numbers[i];
        }
        else {
            if (getDistance(position_l, numbers[i]) < getDistance(position_r, numbers[i])) {
                answer += "L";
                position_l = numbers[i];
            }
            else if (getDistance(position_l, numbers[i]) > getDistance(position_r, numbers[i])) {
                answer += "R";
                position_r = numbers[i];
            }
            else if (getDistance(position_l, numbers[i]) == getDistance(position_r, numbers[i])) {
                if (hand == "left") {
                    answer += "L";
                    position_l = numbers[i];
                }
                else if (hand == "right") {
                    answer += "R";
                    position_r = numbers[i];
                }
            }
        }
                
    }
    return answer;
}