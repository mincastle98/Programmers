#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    string str = "";

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if ((arr1[i] & (1 << j)) || (arr2[i] & (1 << j)))
                str += '#';
            else
                str += ' ';
        }
        answer.push_back(str);
        str = "";
    }

    return answer;
}

int main()
{
    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};
    vector<string> res = solution(n, arr1, arr2);

    for (string s : res)
    {
        cout << s << '/' ;
    }

    return 0;
}