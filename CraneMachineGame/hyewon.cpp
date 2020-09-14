#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> list;

	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j][moves[i]-1] != 0) {
				list.push_back(board[j][moves[i]-1]);
				board[j][moves[i]-1] = 0;
				if (list.size() > 1 && list[list.size() - 1] == list[list.size() - 2]) {
					answer++; answer++;
					list.pop_back();
					list.pop_back();
				}
				break;
			}
		}

	}

	return answer;
}

int main() {
	vector<vector<int>> b = { {0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1},
								{4,2,4,4,2}, {3,5,1,3,1} };
	vector<int> m = { 1, 5, 3, 5, 1, 2, 1, 4 };

	cout << "사라진 인형의 개수는 " << solution(b, m) << endl;
}