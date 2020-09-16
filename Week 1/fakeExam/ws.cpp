#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> ans1;
    vector<int> ans2;
    vector<int> ans3;

    int num = answers.size();

    for (int i = 0; i < num; i++) {
        ans1.push_back(i % 5 + 1);
    }
    for (int i = 0; i < num; i++) {
        if (i % 2 == 0)
            ans2.push_back(2);
        else if (i % 8 == 1)
            ans2.push_back(1);
        else if (i % 8 == 3)
            ans2.push_back(3);
        else if (i % 8 == 5)
            ans2.push_back(4);
        else if (i % 8 == 7)
            ans2.push_back(5);
    }
    for (int i = 0; i < num; i++) {
        if (i % 10 <= 1)
            ans3.push_back(3);
        else if (i % 10 <= 3)
            ans3.push_back(1);
        else if (i % 10 <= 5)
            ans3.push_back(2);
        else if (i % 10 <= 7)
            ans3.push_back(4);
        else if (i % 10 <= 9)
            ans3.push_back(5);
    }

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    for (int i = 0; i < num; i++) {
        if (answers[i] == ans1[i])
            count1++;
    }
    for (int i = 0; i < num; i++) {
        if (answers[i] == ans2[i])
            count2++;
    }
    for (int i = 0; i < num; i++) {
        if (answers[i] == ans3[i])
            count3++;
    }

    if (count1 > count2)
        if (count1 > count3)
            answer.push_back(1);
        else if (count1 == count3) {
            answer.push_back(1);
            answer.push_back(3);
        }
        else
            answer.push_back(3);
    else if (count1 == count2)
        if (count1 > count3) {
            answer.push_back(1);
            answer.push_back(2);
        }
        else if (count1 == count3) {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else
            answer.push_back(3);
    else
        if (count2 > count3)
            answer.push_back(2);
        else if (count2 == count3) {
            answer.push_back(2);
            answer.push_back(3);
        }
        else
            answer.push_back(3);

    return answer;
}

int main() {
    vector<int> answers;
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    solution(answers);
    for (int i = 0; i<3; i++) {
        cout << solution(answers)[i];
    }
}