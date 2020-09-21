#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> pick;
    for (int i = 0; i < numbers.size() - 2; i++) {
        pick.push_back(0);
    }
    for (int i = 0; i < 2; i++) {
        pick.push_back(1);
    }

    do {
        int sum = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (pick[i] == 1) {
                sum += numbers[i];
            }
        }
        answer.push_back(sum);
    } while (next_permutation(pick.begin(), pick.end())); //조합

    sort(answer.begin(), answer.end()); //정렬
    answer.erase(unique(answer.begin(), answer.end()), answer.end()); //지우기

    return answer;
}