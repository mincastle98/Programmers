#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {
        int j = i + 1;
        while (prices[i] <= prices[j] && j < prices.size()) {
            j++;
        }
        if (j == prices.size())
            answer.push_back(j - i - 1);
        else
            answer.push_back(j - i);
    }
    return answer;
}