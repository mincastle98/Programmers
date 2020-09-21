#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int count = 0;
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == lost[i]) {
                reserve.erase(reserve.begin() + j);
                lost.erase(lost.begin() + i);
            }
        }
    }

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == lost[i] - 1) {
                count++;
                reserve.erase(reserve.begin() + j);
                break;
            }
            else if (reserve[j] == lost[i]) {
                count++;
                reserve.erase(reserve.begin() + j);
                break;
            }
            else if (reserve[j] == lost[i] + 1) {
                count++;
                reserve.erase(reserve.begin() + j);
                break;
            }
        }
    }
    answer = n - lost.size() + count;
    return answer;
}