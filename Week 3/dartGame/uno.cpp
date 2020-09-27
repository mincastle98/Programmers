#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    int prevScore = 0;
    int curScore = 0;

    for (size_t i = 0; i < dartResult.size(); i++)
    {
        if (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            answer += prevScore;
            prevScore = curScore;

            curScore = stoi(&dartResult[i]);
            if (curScore == 10)
            {
                i++;
                continue;
            }
        }
        else
        {
            switch (dartResult[i])
            {
            case 'D':
                curScore = curScore * curScore;
                break;
            case 'T':
                curScore = curScore * curScore * curScore;
                break;
            case '*':
                curScore = curScore * 2;
                prevScore = prevScore * 2;
                break;
            case '#':
                curScore = -curScore;
                break;
            default:
                break;
            }
        }
    }
    answer += curScore + prevScore;

    return answer;
}

int main()
{
    string s = "1D2S#10S";

    cout << solution(s) << endl;
    return 0;
}