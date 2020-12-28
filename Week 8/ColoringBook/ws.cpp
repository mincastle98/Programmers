#include <vector>
#include <queue>
using namespace std;

int areaCheck(int i, int j, vector<vector<int>> picture, vector<vector<int>>& isChecked, int m, int n) {
    
    int area = 0;
    isChecked[i][j] = 1;

    queue<pair<int, int>> area_q;
    area_q.push(make_pair(i, j));

    while (area_q.size() != 0) {
        int x = area_q.front().first;
        int y = area_q.front().second;
        area_q.pop();
        area++;

        if (x > 0 && picture[x - 1][y] == picture[i][j] && isChecked[x - 1][y] == 0) {
            area_q.push(make_pair(x - 1, y));
            isChecked[x - 1][y] = 1;
        }
        if (x + 1 < m && picture[x + 1][y] == picture[i][j] && isChecked[x + 1][y] == 0) {
            area_q.push(make_pair(x + 1, y));
            isChecked[x + 1][y] = 1;
        }
        if (y > 0 && picture[x][y - 1] == picture[i][j] && isChecked[x][y - 1] == 0) {
            area_q.push(make_pair(x, y - 1));
            isChecked[x][y - 1] = 1;
        }
        if (y + 1 < n && picture[x][y + 1] == picture[i][j] && isChecked[x][y + 1] == 0) {
            area_q.push(make_pair(x, y + 1));
            isChecked[x][y + 1] = 1;
        }
    }

    return area;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<vector<int>> isChecked;
    isChecked.assign(m, vector<int>(n, 0));

    int area;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && isChecked[i][j] == 0) {
                area=areaCheck(i, j, picture, isChecked, m, n);
                if (area > max_size_of_one_area)
                    max_size_of_one_area = area;
                number_of_area++;
            }
        }
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
