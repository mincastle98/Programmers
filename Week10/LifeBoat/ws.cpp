#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    for (int i = people.size() - 1; i > 0; i--) {
        if (people[i] + people[0] <= limit) {
            for (int j = i - 1; j >= 0; j--) {
                if (people[i] + people[j] <= limit) {
                    people.erase(people.begin() + i);
                    people.erase(people.begin() + j);
                    i--;
                    answer++;
                    break;
                }
            }
        }
        else {
            people.erase(people.begin() + i);
            answer++;
        }
    }
    answer += people.size();
    return answer;
}