#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, day;
    int current = 0, count = 0;

    for (int i = 0; i < progresses.size(); i++)
    {
        current = 100 - progresses[i];
        if (current % speeds[i])
            current = current / speeds[i] + 1;
        else
            current /= speeds[i];
        day.push_back(current);
    }

    while (!day.empty())
    {
        int ind = 0;
        current = day.front();

        for (int i = 0; i < day.size(); i++)
        {
            if (current >= day[i])
                ind++;
            else
                break;
        }

        for (int i = 0; i < ind; i++)
            day.erase(day.begin());
        answer.push_back(ind);
    }
    return answer;
}