#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> now_W;
    now_W.assign(bridge_length, 0);

    for (int i = 0; i < truck_weights.size(); i++) {
        int sum = 0;
        now_W.erase(now_W.begin());
        for (int j = 0; j < bridge_length - 1; j++) {
            sum += now_W[j];
        }
        if (sum + truck_weights[i] <= weight) {
            now_W.push_back(truck_weights[i]);
        }
        else {
            now_W.push_back(0);
            i--;
        }

        answer++;
    }
    return answer + bridge_length;
}