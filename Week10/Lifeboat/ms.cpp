#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), compare);

    for (int i = 0; i < people.size(); i++) {
        if (people[i] + people[people.size() - 1] > limit) {
            people[i] = 0;
            answer++;
        } else {
            people[i] = 0;
            people.erase(people.end() - 1);
            answer++;
        }
    }

    return answer;
}
