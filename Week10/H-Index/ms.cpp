#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    //citations.erase(unique(citations.begin(), citations.end()), citations.begin());

    for (int i : citations) {
        if (i == answer) continue;
        auto iter = find(citations.begin(), citations.end(), i);
        int idx = iter - citations.begin();

        if (idx > i || citations.size() - idx < i) continue;
        else if (i > answer) answer = i;
    }

    return answer;
}

int main(void) {
    solution({3, 0, 6, 1, 5});
    return 0;
}