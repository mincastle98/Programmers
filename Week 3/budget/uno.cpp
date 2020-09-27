#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;
    sort(d.begin(), d.end());

    for (int i : d)
    {
        budget -= i;
        if (budget < 0)
            break;
        answer++;
    }

    return answer;
}

int main()
{
    vector<int> d = {2, 2, 3, 3};
    int b = 10;

    cout << solution(d, b) << endl;

    return 0;
}