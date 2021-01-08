#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<>());
    for (int i = 0; i < people.size(); i++) {
        if (people[i] + people[people.size() - 1] <= limit) {
            people.erase(people.end() - 1);
            answer++;
        }
        else {
            answer++;
        }
    }
    return answer;
}