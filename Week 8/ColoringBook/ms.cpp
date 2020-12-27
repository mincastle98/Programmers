#include <vector>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<vector<int>> picture_global;
vector<vector<int>> checked;
int max_x, max_y;

int check(int x, int y, int color, int cnt) {
    if (picture_global[x][y] == color) {
        checked[x][y] = 0;
    } else return cnt;

    if (y < max_y - 1 && checked[x][y + 1])
        cnt = check(x, y + 1, color, cnt);
    if (x < max_x - 1 && checked[x + 1][y])
        cnt = check(x + 1, y, color, cnt);
    if (y > 0 && checked[x][y - 1])
        cnt = check(x, y - 1, color, cnt);
    if (x > 0 && checked[x - 1][y])
        cnt = check(x - 1, y, color, cnt);

    if (picture_global[x][y] == color){
        cout<< x << " " << y << endl;
        return cnt + 1;
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    picture_global = picture;
    for (int i = 0; i < m; i++) {
        vector<int> tmp(n, 1);
        checked.push_back(tmp);
    }
    max_x = m;
    max_y = n;

    int tmp = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] == 0 || !checked[i][j]) continue;
            tmp = check(i, j, picture[i][j], 0);
            if (tmp) {
                number_of_area++;
                if (tmp > max_size_of_one_area)
                    max_size_of_one_area = tmp;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
int main(void) {
    solution(13, 16,
             {
                     {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                     {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                     {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                     {0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0},
                     {0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0},
                     {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                     {0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0},
                     {0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0},
                     {0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 0},
                     {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                     {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}});
    return 0;
}