using namespace std;
long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}

long long solution(int w, int h) { //메모리 공간 overflow 때문에 long 타입 사용
	long long answer = 1;
	long long a = w;
	long long b = h;
	if ((a == 1) || (b == 1)) //w, h 둘 중 하나라도 1이면, 0임
		answer = 0;
	else
	{
		if (gcd(a, b) == 1)
			answer = ((a*b) - (a + b - 1));
		else
			answer = ((a*b) - (a + b - gcd(a, b)));
	}
	return answer;
}
