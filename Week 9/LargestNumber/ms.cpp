#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
        else {
            if (min(a.size(), b.size()) == a.size() && i == a.size() - 1) {
                if (b[i + 1] > b[i]) return false;
                else return true;
            } else if (min(a.size(), b.size()) == b.size() && i == b.size() - 1) {
                if (a[i + 1] > a[i]) return true;
                else return false;
            }
            if (a[i + 1] > a[i]) {
                if (b[i + 1] > b[i])
                    continue;
                else return true;
            } else if (b[i + 1] > b[i]) {
                if (a[i + 1] > a[i])
                    continue;
                else return false;
            } else continue;

        }
    }
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<vector<int>> nums;
    for (int i : numbers) {
        vector<int> tmp;
        while (i >= 10) {
            tmp.push_back(i % 10);
            i /= 10;
        }
        tmp.push_back(i);
        reverse(tmp.begin(), tmp.end());
        nums.push_back(tmp);
    }

    sort(nums.begin(), nums.end(), compare);

    for (vector<int> i : nums) {
        for (int j : i) {
            answer += j + '0';
        }
    }

    return answer;
}

int main(void) {
    solution({3, 30, 34, 5, 9});
    return 0;
}