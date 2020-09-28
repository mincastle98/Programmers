using namespace std;

long long solution(int w, int h) {
    long long answer;
    long long count = 0;
    for (int i = 0; i < w; i++) {
        count += (long long)h * i / w;
    }
    answer = count * 2;
    return answer;
}