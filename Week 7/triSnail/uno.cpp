#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> snail(n + 1, vector<int>(n + 1));
    int maxValue = (n * (n + 1)) / 2;
    int top = 1;
    int bottom = n;
    int left = 1;
    int right = 0;
    int num = 1;
    int flag = 0;
    
    while (num <= maxValue)
    {
        if (flag == 0)
        {
            for (int i = top; i <= bottom; i++)
                snail[i][left] = num++;
            top++;
            left++;
            flag = 1;
        }
        else if (flag == 1)
        {
            for (int i = left; i <= bottom - right; i++)
                snail[bottom][i] = num++;
            bottom--;
            flag = 2;
        }
        else if (flag == 2)
        {
            for (int i = bottom; i >= top; i--)
                snail[i][i - right] = num++;
            right++;
            top++;
            flag = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            answer.push_back(snail[i][j]);
        }
    }

    return answer;
}

int main()
{
    vector<int> res;
    res = solution(6);

    for (int t : res)
        cout << t << endl;
    return 0;
}