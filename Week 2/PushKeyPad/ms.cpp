// PushKeyPad
// Created by 김민성 on 2020/09/16.

#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> getPosition(int num) {
    vector<int> position(2);
    int x, y;

    //num_x
    if (num == 0) x = 1;
    else {
        x = (num % 3) - 1;
        if (num % 3 == 0) x = 2;
    }
    //num_y
    if (num == 0) y = 3;
    else {
        y = num / 3;
        if (num % 3 == 0) y--;
    }

    position[0] = x;
    position[1] = y;

    return position;

}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<vector<int>> keypad(10);
    vector<int> position(2);
    vector<int> lPosition(2);
    vector<int> rPosition(2);

    lPosition = {0, 3};
    rPosition = {2, 3};

    //keypad setting
    for (int i = 0; i < 10; i++) {
        keypad[i] = getPosition(i);
    }

    for (int i = 0; i < numbers.size(); i++) {
        vector<int> numPosition = getPosition(numbers[i]);

        if (numbers[i] % 3 == 1) {      //in line 1
            answer.push_back('L');

            lPosition = numPosition;
        } else if (numbers[i] != 0 && numbers[i] % 3 == 0) {        //in line 3
            answer.push_back('R');

            rPosition = numPosition;
        } else {          //in line 2
            char closerHand;
            int lDistance = abs(lPosition[0] - numPosition[0]) + abs(lPosition[1] - numPosition[1]);
            int rDistance = abs(rPosition[0] - numPosition[0]) + abs(rPosition[1] - numPosition[1]);

            if (lDistance == rDistance) closerHand = toupper(hand[0]);
            else {
                closerHand = lDistance > rDistance ? 'R' : 'L';
            }

            answer.push_back(closerHand);
            switch (closerHand) {
                case 'L':
                    lPosition = numPosition;
                    break;
                case 'R':
                    rPosition = numPosition;
                    break;
            }
        }
    }

    return answer;
}

int main(void) {

    solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");

    return 0;
}