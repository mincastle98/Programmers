#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();

    for (int i = 1; i <= s.length() / 2; i++) {
        int ans_tmp = s.length();
        vector<string> temp;
        vector<string> temp_;
        vector<pair<string, int>> cnt;
        for (int j = 0; j < s.length(); j += i) {
            temp.push_back(s.substr(0 + j, i));
        }

        temp_.resize((int) temp.size());
        copy(temp.begin(), temp.end(), temp_.begin());
        temp_.erase(unique(temp_.begin(), temp_.end()), temp_.end());
        if(temp.size() == temp_.size()) continue;

        int idx = 0;
        int cnt_ = 0;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == temp_[idx])
                cnt_++;
            else {
                cnt.push_back(make_pair(temp_[idx], cnt_));
                idx++;
                j--;
                cnt_= 0;
            }
        }
        cnt.push_back(make_pair(temp_[idx], cnt_));

        for (auto j : cnt) {
            if (j.second == 2)
                ans_tmp -= i - 1;
            else if (j.second == 1000)
                ans_tmp -= i - 4;
            else if (j.second >= 100)
                ans_tmp -= i * (j.second - 2) + i - 3;
            else if (j.second >= 10)
                ans_tmp -= i * (j.second - 2) + i - 2;
            else if (j.second >= 3)
                ans_tmp -= i * (j.second - 2) + i - 1;
        }

        if (answer >= ans_tmp)
            answer = ans_tmp;
    }

    return answer;
}