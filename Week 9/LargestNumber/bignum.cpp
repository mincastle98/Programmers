#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
	string answer = "";
	string tempo = "";
	int size = numbers.size(); //벡터 사이즈 값
	vector<string> result;
	vector<int> por;
	vector<int> sta;

	vector<pair<string, string>> ppp;

	for (int i = 0; i < size; i++)
		tempo += to_string(numbers[i]);
	int container = tempo.size(); //형성된 문자열 길이를 저장
	
	for (int k = 0; k < container; k++)
		result.push_back(to_string(numbers[k])); //문자열 벡터에 다시금 저장

	for (int j = 0; j < container; j++)
		sta.push_back(stoi(result[j].substr(0, 1)));

	for(int p = 0; p < )
	ppp.push_back(make_pair())

	sort(sta.begin(), sta.end());


	for (int j = 0; j < container; j++)
		por.push_back(result[j].length());
	
	
	
	

	return answer;
}

void main()
{

}