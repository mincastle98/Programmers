#include <string>
#include <vector>
#include <bitset> //bitset을 사용하기 위해
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<string> repos, depos; //2진수로 변환된 값을 저장하기 위한 2개의 string 배열
	string nae; //비밀지도를 표시하기 위한 string
	for (int i = 0; i < arr1.size(); i++) //arr1[i]에 있는 모든 숫자를 2진수로 변환한 후, string으로 변환하여 repos에 저장
		repos.push_back(bitset<16>(arr1[i]).to_string());
	for (int a = 0; a < arr2.size(); a++) //동일한 방법을 arr2[a]에 적용
		depos.push_back(bitset<16>(arr2[a]).to_string());

	for (int j = 0; j < n; j++)
	{
		for (int m = 16 - n; m < 16; m++) //16-n을 안했더니 16자리 2진수의 첫 값부터 우르르 나와서 
			//16-n을 함으로써, 숫자가 있는 부분부터 출력되게 해 줌
		{
			if ((repos[j][m] == '0') && (depos[j][m] == '0'))
				nae = nae + " "; //값이 0이면 공백을 저장
			else
				nae = nae + "#"; //값이 0이 아니라면 #을 저장
		}
		answer.push_back(nae); //완성된 지도 값을 answer에 저장
		nae = ""; //nae 값을 초기화 사켜서 기존에 저장되 있던 값에 또 문자가 추가되는 불상사를 
	}
	return answer;
}


