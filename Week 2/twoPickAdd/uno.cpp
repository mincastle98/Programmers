#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq; // 오름차순
    
    for (size_t i = 0; i < numbers.size() - 1; i++)
        for (size_t j = i + 1; j < numbers.size(); j++)
            pq.push(numbers[i] + numbers[j]);

    while (!pq.empty())
    {        
        if(!answer.empty() && answer.back() == pq.top())
        {
            pq.pop();
            continue;
        }
        answer.push_back(pq.top());
        pq.pop();
    }
    return answer;
}

int main()
{
    
    vector<int> n = {2, 1, 3, 4, 1};
    vector<int> res = solution(n);
    
    for (int i : res)
        cout << i << endl;
    return 0;
}