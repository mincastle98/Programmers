#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<bool>> book;
queue <int> q;
int cnt;

int coloring(int m, int n, int i, int j, int color, vector<vector<int>> picture) {

	book[i][j] = true;

	if (j + 1 < n && book[i][j+1]==false && color == picture[i][j + 1]) {
		q.push(i); q.push(j + 1); book[i][j + 1] =true;	cnt++;
	}
	if (i + 1 < m && book[i+1][j] == false && color == picture[i+1][j]) {
		q.push(i + 1); q.push(j); book[i + 1][j] =true;	cnt++;
	}
	if (j - 1 > 0 && book[i][j-1] == false && color == picture[i][j - 1]) {
		q.push(i); q.push(j - 1); book[i][j - 1] =true;	cnt++;
	}
	if (i - 1 > 0 && book[i-1][j] == false && color == picture[i-1][j]) {
		q.push(i - 1); q.push(j); book[i - 1][j] =true;	cnt++;
	}

	while (!q.empty()) {
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
	
		coloring(m, n, x, y, color, picture);
	}
	return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	
	book = vector<vector<bool>>();
	q = queue<int>();
	cnt = 0;
	
	vector <bool> book_;
	vector <int> count;
	int size;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			book_.push_back(false);
		}
		book.push_back(book_);
		book_.clear();
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (book[i][j])
				continue;
			if (picture[i][j] == 0)
				continue;
			cnt = 1;
			size=coloring(m,n,i, j, picture[i][j],picture);
			count.push_back(size);
			number_of_area++;
		}
	}
	sort(count.begin(), count.end(), greater<int>());
	
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = count[0];

	return answer;
}

int main() {
	int m = 6;
	int n = 4;
	vector<vector<int>> picture = { {1,1,1,0},{1,1,1,0},{0,0,0,1},{0,0,0,1},{0,0,0,1},{0,0,0,1} };
	solution(m, n, picture);
}