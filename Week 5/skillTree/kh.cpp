#include <string>
#include <vector>
//#include<algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int flag = 1;
    int cnt = 0;
    int check = 0;

    for (int i = 0; i < skill_trees.size(); i++) {
        string order = skill_trees[i];

        for (int j = 0; j < order.size(); j++) {
            int nDelimiter = skill.find(order[j]);

            if (nDelimiter == (-1) || nDelimiter > 26) 
                continue;
 
            else if (nDelimiter != check) {
                flag = 0;
                break;
            }
            else
                check++;
        }
        if (flag) 
            cnt++;
      
        check = 0;
        flag = 1;
    }
    answer = cnt;
    return answer;
}