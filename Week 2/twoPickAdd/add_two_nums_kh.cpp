#include <string>
#include <vector>
#include<algorithm>
//#include<iostream>
//made by ¿Ã∞≠»Ò
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
        
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
   
    for (int i = 0; i < answer.size(); i++) {
        for (int j =  i+1; j < answer.size(); j++) {
            if (answer[i] == answer[j])
                answer.erase(remove(answer.begin()+j,answer.end(),answer[i]),answer.end());
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
/*
int main() {
    vector<int>numbers = { 2,2,3,3,4,4 };
    
    vector<int>answer(solution(numbers));
    for (int i = 0; i < answer.size(); i++) {
        cout << answer.at(i) << endl;
    }
    return 0;
}*/