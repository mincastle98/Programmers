#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    map<char, int> priority;
    int p = 1, flag = 1;

    for (int i = 0; i < skill.size(); i++)
        priority.insert(make_pair(skill[i], i + 1));

    for (string s : skill_trees)
    {
        p = 1;
        flag = 1;
        for (char c : s)
        {
            if (priority.find(c) != priority.end())
            {
                if (priority[c] > p)
                {
                    flag = 0;
                    break;
                }
                p++;
            }
        }
        if (flag == 1)
            answer++;
    }
    return answer;
}