#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string>arr1_s;
    vector<string>arr2_s;
    string temp;
    int sq = 1;

    for (int i = 0; i < n; i++) {
        sq *= 2;
    }

    for (int j = 0; j < arr1.size(); j++) {
        temp.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr1[j] & (1 << i))
                temp += '#';
            else
                temp += ' ';
        }
        arr1_s.push_back(temp);
    }

    for (int j = 0; j < arr2.size(); j++) {
        temp.clear();
        for (int i = n-1; i >= 0; i--)
        {
            if (arr2[j] & (1 << i))
                temp += '#';
            else
                temp += ' ';
        }
        arr2_s.push_back(temp);
    }
   
    for (int i = 0; i < n; i++) {
        temp.clear();
        for (int j = 0; j < n; j++) {
            if (arr1_s[i][j] == '#' || arr2_s[i][j] == '#')
                temp += '#';
            else if (arr1_s[i][j] != '#' && arr2_s[i][j] != '#')
                temp += ' ';
        }
        answer.push_back(temp);
    }
    
    return answer;
}

int main() {
    vector<int>arr1 = { 9, 20, 28, 18, 11 };
    vector<int>arr2 = { 30, 1, 21, 17, 28 };
    vector<string>answer = solution(5, arr1, arr2);
}