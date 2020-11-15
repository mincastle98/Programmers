#include <string>
#include <vector>
#include <queue>

using namespace std;

class Truck {
public:
    int weight;
    int outTime;

    Truck (int weight, int outTime) {
        this->weight = weight;
        this->outTime = outTime;
    }
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    queue<Truck> nowOn;
    int nowWeight = 0;
    int i = 0;

     do {
        for (; i < truck_weights.size() && nowWeight + truck_weights[i] <= weight && answer != nowOn.front().outTime; i++) {
            nowOn.push(Truck(truck_weights[i], answer + bridge_length));
            nowWeight += truck_weights[i];
            answer++;
        }

        answer = nowOn.front().outTime;

        nowWeight -= nowOn.front().weight;
        nowOn.pop();

     } while (i < truck_weights.size() || !nowOn.empty());

    return answer;
}