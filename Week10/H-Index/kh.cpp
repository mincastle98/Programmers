#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int temp = 0;
    vector<int>size;
    sort(citations.begin(),citations.end());

    int h;
    int front, end, length;
    /*
    for (int i = 0; i < citations.size(); i++) {
        h = citations[i];
        for (int j = 0; j < citations.size(); j++) {
            if (h <= citations[j]) {
                temp++;
                if (temp == h)
                    size.push_back(temp);
            }
        }
        temp = 0;
    }*/
    length = citations.size();
    for (int i = 0; i < citations.size(); i++) {
        front = 0;
        h = citations[i];
        end = length;
        for (int j = 0; j < citations.size(); j++) {
            if (h > citations[j])
                front++;
        }
        end = length - front;
        if (end >= h && front <= h)
            size.push_back(h);
    }

    int max = size[0];
    for (int i = 0; i < size.size(); i++) {
        if (size[i] >= max)
            max = size[i];
    }
    answer = max;

    return answer;
}

int main() {
    vector<int>citations = { 3, 0, 6, 1, 5 };
    sort(citations.begin(), citations.end());
    cout << solution(citations) << endl;
    
}