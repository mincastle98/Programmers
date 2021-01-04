#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());

    for (int i = 1; i <= citations.size(); i++) {
        if (i <= citations[citations.size() - i]) answer = i;
        else break;
    }

    return answer;
}