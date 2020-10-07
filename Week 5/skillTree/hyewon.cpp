#include <string>
#include <vector>

using namespace std;

vector<char> pullOut(string skill, string leaf) {
	vector<char> skills;
	for (int i = 0; i < leaf.size(); i++) {
		for (int j = 0; j < skill.size(); j++) {
			if (skill[j] == leaf[i]) skills.push_back(leaf[i]);
		}
	}
	return skills;
}

bool compare(string str, vector<char> c) {
	if (str.size() != c.size()) {
		for (int j = 0; j < str.size() - c.size(); j++) {
			c.push_back(' ');
		}
	}
	for (int i = 0; i < c.size(); i++) {
		if (c[i] == ' ') break;
		if (str[i] != c[i]) return false;
	}
	return true;
}

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++) {
		vector<char> p = pullOut(skill, skill_trees[i]);
		if (compare(skill, p) == true) answer++;		
	}

	return answer;
}