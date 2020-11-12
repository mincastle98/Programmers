#include <string>
#include <vector>
#include <iostream>

using namespace std;

//°¥¾Æ¾þ±â

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1;
	int b_t_w = 0;
	int b_t_c = 0;
	int len = 0;
	int flag = 0;

	for (int i = 0; i < truck_weights.size(); i++) {
		b_t_w += truck_weights[i];
		b_t_c++;
		len += bridge_length;

		while (len >= 0) {
			answer++;
			len -= b_t_c;

			if (len == 0) {
				b_t_w = 0;
				b_t_c = 0;
				break;
			}
			else if ((i<truck_weights.size()-1)&&(weight - b_t_w >= truck_weights[i + 1])) {
				b_t_w += truck_weights[i + 1];
				b_t_c++;

				if (b_t_c == truck_weights.size())
					flag = 1;

				len += bridge_length;
				i++;
			}
		    if (flag==0&&len < b_t_c) {
				b_t_c--;
				b_t_w -= truck_weights[i-1];
			}


			if (flag == 1 && answer > bridge_length ) {
				b_t_c--;
				b_t_w -= truck_weights[i - 1];
			}
		}
	}
	
	return answer;
}

int main() {
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights = { 7,4,5,6 };

	cout<< solution(bridge_length, weight, truck_weights) << endl;
}