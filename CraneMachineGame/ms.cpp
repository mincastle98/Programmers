// CraneMachineGame
// Created by 김민성 on 2020/09/08.

#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> picked;

    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1] != 0) {
                picked.push_back(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
                break;
            }
        }

        if (picked.size() >= 2 && picked.at(picked.size() - 2) == picked.back()) {
            picked.pop_back();
            picked.pop_back();
            answer += 2;
        }
    }

    return answer;
}

int main() {

    vector<vector<int>> board = {{0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 3},
                                 {0, 2, 5, 0, 1},
                                 {4, 2, 4, 4, 2},
                                 {3, 5, 1, 3, 1}
    };

    solution(board, {1, 5, 3, 5, 1, 2, 1, 4});

    return 0;
}