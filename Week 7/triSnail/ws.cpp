#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>>tri;
    for (int i = 1; i <= n; i++) {
        vector<int>vec_tri(i);
        tri.push_back(vec_tri);
    }
    int i = 0;
    int j = 0;
    int num = 1;
    for (int k = n; k > 0; k--) {
        if ((n - k) % 3 == 0) {
            for (int m = 0; m < k; m++) {
                tri[i][j] = num;
                num++;
                if (m != k - 1)
                    i++;
                else
                    j++;
            }
        }
        else if ((n - k) % 3 == 1) {
            for (int m = 0; m < k; m++) {
                tri[i][j] = num;
                num++;
                if (m != k - 1)
                    j++;
                else {
                    i--;
                    j--;
                }
            }
        }
        else {
            for (int m = 0; m < k; m++) {
                tri[i][j] = num;
                num++;
                if (m != k - 1) {
                    i--;
                    j--;
                }
                else
                    i++;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int m = 0; m <= k; m++) {
            answer.push_back(tri[k][m]);
        }
    }

    return answer;
}