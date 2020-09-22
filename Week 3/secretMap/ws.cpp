#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector < vector <int> > temp1;
    temp1.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int j = 0;
        if (arr1[i] == 0)
            continue;
        else {
            while (arr1[i] > 1) {
                if (arr1[i] % 2 == 1)
                    temp1[i][n - 1 - j] = 1;
                else
                    temp1[i][n - 1 - j] = 0;

                arr1[i] /= 2;
                j++;
            }
            temp1[i][n - 1 - j] = 1;
        }
    }
    vector < vector <int> > temp2;
    temp2.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int j = 0;
        if (arr2[i] == 0)
            continue;
        else {
            while (arr2[i] > 1) {
                if (arr2[i] % 2 == 1)
                    temp2[i][n - 1 - j] = 1;
                else
                    temp2[i][n - 1 - j] = 0;

                arr2[i] /= 2;
                j++;
            }
            temp2[i][n - 1 - j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        string ans = "";
        for (int j = 0; j < n; j++) {
            if (temp1[i][j] || temp2[i][j]) {
                ans += "#";
            }
            else {
                ans += " ";
            }
        }
        answer.push_back(ans);
    }

    return answer;
}