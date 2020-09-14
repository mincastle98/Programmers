#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<int> pick;

    int i = 0;
    while (i < moves.size()) {
        int now = moves[i] - 1;

        for (int j = 0; j < board[0].size(); j++) {
            if (board[j][now] == 0)
                continue;
            else {
                pick.push_back(board[j][now]);
                board[j][now] = 0;
                break;
            }
        }

        i++;
    }

    for (int i = 0; i < pick.size() - 1; i++) {
        if (pick.size()>=2&&pick[i] == pick[i + 1]) {
            answer += 2;
            pick.erase(pick.begin() + i);
            pick.erase(pick.begin() + i);

            if (i == 0)
                i--;
            else
                i = i - 2;

        }
    }

    return answer;
}