#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 101;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
bool check[MAX][MAX];
int bfs(int x, int y, vector<vector<int>>& map) {
    int area = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = true;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (0 > nx || nx >= map.size() || 0 > ny || ny >= map[0].size()) continue;
            if (check[nx][ny] || map[x][y] != map[nx][ny]) continue;
            q.push(make_pair(nx, ny)), area++, check[nx][ny] = true;
        }
    }
    return area;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    memset(check, false, sizeof(check));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 0 || check[i][j]) continue;
            number_of_area++;
            int now = bfs(i, j, picture);
            max_size_of_one_area = max(max_size_of_one_area, now);
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
