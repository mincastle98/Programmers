#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    
    int index = -1;
    int num[3] = { 0 };
    for (int i = 0; i < dartResult.size(); i++) {
        
        if (48 <= dartResult[i] && dartResult[i] <= 57) {
            index++;
            num[index] = dartResult[i] - '0';
            if (48 <= dartResult[i + 1] && dartResult[i + 1] <= 57){
                num[index] = 10;
                i++;
            }
        }

        else if (dartResult[i] == 'D')
            num[index] *=  num[index];

        else if (dartResult[i] == 'T')
            num[index] *=  num[index] * num[index];

        else if (dartResult[i] == '#')
            num[index] *=  (-1);

        else if (dartResult[i] == '*') {
            num[index] *= 2;
            if(index>0)
                num[index - 1] *= 2;
        }
    }

    for (int i = 0; i < 3; i++) {
        answer += num[i];
    }
    
    return answer;
}
