#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int visit[101][101];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int idx, maxArea;
void bfs(int a, int b, vector<vector<int>> picture, int m, int n) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	int cnt = 1;
	visit[a][b] = cnt;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
		
		}
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	idx = maxArea = 0;
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (picture[i][j] != 0 && visit[i][j] == 0) {
				idx++;
				bfs(i, j, picture, m, n);
			}

	vector<int> answer(2);
	return answer;
}