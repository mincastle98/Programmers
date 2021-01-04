#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());

    for (int i = 0; i < citations.size(); i++) {
        if (i > 1 && citations[i] == citations[i - 1]) continue;
        if (i > citations[i] || citations.size() - i < citations[i]) continue;

        else if (i > answer) answer = citations[i];
    }

    return answer;
}

int main(void) {
    solution({0, 0, 0, 0, 0, 0, 2, 2});
    return 0;
}