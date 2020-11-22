#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail(n);
    vector<vector<int>> tmp(n);
    int max = (2 * n + 1) / 2;
    int val = 1;
    int cycle = 0;

    for (int type = n; type > 0; type--) {
        switch ((n - type) % 3) {
            case 0:
                for (int i = 0; i < type; i++) {
                    snail[i + 2 * cycle].push_back(val++);
                }
                break;
            case 1:
                for (int i = 0; i < type; i++) {
                    snail[n - 1 - cycle].push_back(val++);
                }
                break;
            case 2:
                for (int i = 0; i < type; i++) {
                    tmp[n - 2 - cycle - i].push_back(val++);
                }
                cycle++;
                break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; !tmp[i].empty(); j++) {
            snail[i].push_back(tmp[i].back());
            tmp[i].pop_back();
        }
    }

    for (auto i : snail) {
        answer.insert(answer.end(), i.begin(), i.end());
    }

    return answer;
}


