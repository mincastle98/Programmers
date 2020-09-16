#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<int> pick;

    int i = 0;
    int count = 0;

    while (i < moves.size()) {
        int now = moves[i] - 1;

        for (int j = 0; j < board[0].size(); j++) {
            if (board[j][now] == 0)
                continue;
            else {
                pick.push_back(board[j][now]);
                count++;
                board[j][now] = 0;
                break;
            }

        }
        if (count > 1) {
            if (pick[count - 1] == pick[count - 2]) {
                answer = answer + 2;
                pick.erase(pick.begin() + count - 2);
                pick.erase(pick.begin() + count - 2);
                count -= 2;
            }
        }

        i++;
    }

    return answer;
}