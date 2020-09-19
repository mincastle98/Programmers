#include <string>
#include <vector>

using namespace std;

class Point {
	int m_x, m_y;
public:
	Point() {}
	Point(int x, int y) { m_x = x; m_y = y; }
	int getX() { return m_x; }
	int getY() { return m_y; }
};

string solution(vector<int> numbers, string hand) {
	string answer = "";
	vector<Point> p;
	vector<int> left_turn, right_turn;
	int left_value = 0, right_value = 0;

	for (int i = 0; i <= 9; i++) {
		if (i == 0) {
			p.push_back(Point(3, 1));
		}
		else {
			if (i == 1 || i == 2 || i == 3) {
				p.push_back(Point(0, (i - 1) % 3));
			}
			else if (i == 4 || i == 5 || i == 6) {
				p.push_back(Point(1, (i - 1) % 3));
			}
			else if (i == 7 || i == 8 || i == 9) {
				p.push_back(Point(2, (i - 1) % 3));
			}
		}
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] % 3 == 1) {
			answer += "L";
			left_turn.push_back(numbers[i]);
		}
		else if (numbers[i] != 0 && numbers[i] % 3 == 0) {
			answer += "R";
			right_turn.push_back(numbers[i]);
		}
		else {
			if (left_turn.empty())
				left_value = abs(p[numbers[i]].getX() - 3) + abs(p[numbers[i]].getY() - 0);
			else
				left_value = abs(p[numbers[i]].getX() - p[left_turn.back()].getX()) + abs(p[numbers[i]].getY() - p[left_turn.back()].getY());

			if (right_turn.empty())
				right_value = abs(p[numbers[i]].getX() - 3) + abs(p[numbers[i]].getY() - 2);
			else
				right_value = abs(p[numbers[i]].getX() - p[right_turn.back()].getX()) + abs(p[numbers[i]].getY() - p[right_turn.back()].getY());


			if (left_value > right_value) {
				answer += "R";
				right_turn.push_back(numbers[i]);
			}
			else if (left_value < right_value) {
				answer += "L";
				left_turn.push_back(numbers[i]);
			}
			else {
				if (hand == "right") {
					answer += "R";
					right_turn.push_back(numbers[i]);
				}
				else if (hand == "left") {
					answer += "L";
					left_turn.push_back(numbers[i]);
				}
			}
		}
	}

	return answer;
}