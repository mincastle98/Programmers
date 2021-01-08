#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    for (int i = people.size() - 1; i >= 0; i--) {
        if (people[i] + people[0] <= limit) {
            people.erase(people.begin());
            i--;
            answer++;
        }
        else {
            answer++;
        }
    }
    return answer;
}