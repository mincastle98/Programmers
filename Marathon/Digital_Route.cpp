#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int main() {
	string digit_s;
	int digit_a[10];
	int count = 0;
	int size;

	for (int i = 0; i < 1000; i++) {
		cin >> digit_s;
		count++;
		if (digit_s == "0")
			break;
		int route = 0;
		int route2 =0;

		
			size = digit_s.length();
			for (int k = 0; k < size; k++) {
				digit_a[k] = digit_s[k] - '0';
			}
		
		
			size = digit_s.length();
			for (int k = 0; k < size; k++) {
				route += digit_a[k];
			}
		
		
			if (route >= 10) {
				digit_s = to_string(route);
				size = digit_s.length();
				for (int k = 0; k < size; k++) {
					digit_a[k] = digit_s[k] - '0';
					route2 += digit_a[k];
					route = route2;
				}
			}
			cout << route << endl;
		}

}