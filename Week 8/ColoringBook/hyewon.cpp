#include <vector>
#include <iostream>
using namespace std;

int checkColor(int pos, int i, int j, vector<vector<int>> &picture) {
	int result = 1;
	int row = picture.size();  // 6
	int col = picture[0].size(); // 4
	if (i < 0 || i >= row || j < 0 || j >= col) return 0;
	else {
		if (picture[i][j] != pos) return 0;
		else {
			picture[i][j] = 0; //visited
			result += checkColor(pos, i + 1, j, picture);
			result += checkColor(pos, i, j + 1, picture);
			result += checkColor(pos, i - 1, j, picture);
			result += checkColor(pos, i, j - 1, picture);
		}
	}
	return result;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0) {
				int numOfColors = checkColor(picture[i][j], i, j, picture);
				if (numOfColors != 0) number_of_area++;
				if (numOfColors > max_size_of_one_area)
					max_size_of_one_area = numOfColors;
			}
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}

int main() {
	vector<vector<int>> p = { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} };
	vector<int> answer = solution(6, 4, p);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
}