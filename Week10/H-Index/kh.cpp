#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int>size;
    sort(citations.begin(),citations.end());

    int h = 0;
    int front, end, length;
   
    length = citations.size();
    for (int i = 0; i < citations.size(); i++) {
        front = 0;
        h++;
        end = length;
        for (int j = 0; j < citations.size(); j++) {
            if (h > citations[j])
                front++;
        }
        end = length - front;
        if (end >= h && front <= h)
            size.push_back(h);
    }

    if (size.size() == 0) return 0;

    int max = size[0];
    for (int i = 0; i < size.size(); i++) {
        if (size[i] >= max)
            max = size[i];
    }

    answer = max;

    return answer;
}

int main() {
    vector<int>citations = { 0,0,0 };
    sort(citations.begin(), citations.end());
    cout << solution(citations) << endl;
    
}
