#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> arr(n + 2, 0); // Prevent overflow

    for (int i : lost)
        arr[i]--;
    for (int i : reserve)
        arr[i]++;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == -1)
        {
            if (arr[i - 1] > 0){
                arr[i] = 0;
                arr[i - 1] = 0;
            }
            else if (arr[i + 1] > 0){
                arr[i] = 0;
                arr[i + 1] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (arr[i] >= 0)
            answer++;

    return answer;
}

int main()
{
    int n = 5;
    vector<int> l = {2, 4};
    vector<int> r = {1, 3, 5};
    cout << solution(n, l, r);
    return 0;
}