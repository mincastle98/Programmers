#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {

    multimap<string, string> mm;
    for (int i = 0; i < clothes.size(); i++) {
        mm.insert(pair<string, string>(clothes[i][1], clothes[i][0]));
    }

    multimap<string, string>::iterator iter;
    int answer = (mm.count(mm.begin()->first) + 1);
    string key_pre = mm.begin()->first;
    for (iter = mm.begin(); iter != mm.end(); ++iter) {
        if (iter->first != key_pre)
            answer *= (mm.count(iter->first) + 1);
        key_pre = iter->first;
    }

    answer--;
    return answer;
}