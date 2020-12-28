#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i <= s.size() / 2 + 1; i++)
    {
        int cnt = 1, tmp = 0;
        string current = s.substr(0, i);

        for (int j = i; j < s.size(); j += current.size())
        {
            if (current == s.substr(j, i))
                cnt++;
            else
            {
                if (cnt == 1)
                    tmp += current.size();
                else
                    tmp += (to_string(cnt).size() + current.size());
                current = s.substr(j, i);
                cnt = 1;
            }
        }
        if (cnt == 1)
            tmp += current.size();
        else
            tmp += (to_string(cnt).size() + current.size());
        answer = tmp < answer ? tmp : answer;
    }
    return answer;
}