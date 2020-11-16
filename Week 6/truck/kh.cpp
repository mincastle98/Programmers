#include <string>
#include <vector>
using namespace std;
int EndTime[10010];
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int Total = 0;
    int Time = 1;
    int Front = 0;
    int Idx = 0;
    for (int i = 0; i < truck_weights.size(); )
    {
        int CS = truck_weights[i];
        for (int j = Front; j < i; j++)
        {
            if (EndTime[j] == Time)
            {
                Total = Total - truck_weights[j];
                Front++;
            }
        }

        if (Total + CS <= weight)
        {
            Total = Total + CS;
            EndTime[i++] = Time + bridge_length;
            Time++;
        }
        
        else
        {
            while (1)
            {
                if (Total + CS <= weight) break;
                Total = Total - truck_weights[Front];
                Time = EndTime[Front++];
            }
            Total = Total + CS;
            EndTime[i++] = Time + bridge_length;
            Time++;
        }
    }
    Time = EndTime[truck_weights.size() - 1];
    return Time;
}


