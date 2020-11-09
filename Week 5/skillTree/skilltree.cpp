#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;
	int end = skill.length(); //스킬의 길이
	int tmp_len; //스킬트리 문자열의 길이
	stack<char> tmp; //스킬의 길이 뒤에서 부터 저장할 stack
	stack<char> ptr;
	int count = 0;

	for (int i = 0; i < end; i++)
		ptr.push(skill[i]);

	for (int j = 0; j < skill_trees.size(); j++)
	{
		for (int k = 0; k < skill_trees[j].length(); k++)
		{
			for (int p = 0; p < skill.length(); p++)
			{
				if (skill_trees[j][k] == skill[p])
				{
					tmp.push(skill[p]);
				}
			}
		}
		if (tmp.size() == 0)
		{
			answer++;
		}
		else
		{
			while (!tmp.empty() && (end - 1) >= 0)
			{
				if (tmp.top() == skill[end - 1])
				{
					ptr.pop();
					tmp.pop();
					count = 1;
				}
				else if (tmp.top() != skill[end - 1])
				{
					if (count == 0)
						ptr.pop();
					else if (count == 1)
						tmp.pop();
				}
			}
			if (tmp.empty() && ptr.empty())
			{
				answer++;
				for (int i = 0; i < end; i++)
					ptr.push(skill[i]);
				count = 0;
			}
			else if (tmp.empty() && !ptr.empty())
			{
				end = skill.length();
				while (!ptr.empty())
					ptr.pop();
				for (int i = 0; i < end; i++)
					ptr.push(skill[i]);
				count = 0;
			}
			else 
			{
				end = skill.length();
				while (!tmp.empty())
					tmp.pop();
				count = 0;
			}
		}
	}
	return answer;
}

void main()
{
	string skill = "CBD";
	vector<string> skill_trees;
	skill_trees.push_back("BACDE");
	skill_trees.push_back("CBADF");
	skill_trees.push_back("AECB");
	skill_trees.push_back("BDA");
	int k = solution(skill, skill_trees);
	cout << k << endl;
}

/*
while ((end-1) != 0 && !tmp.empty())
{
if (tmp.top() == skill[end - 1])
{
tmp.pop();
end--;if (tmp.top() != skill[end - 1])
break;

}
else if (tmp.top() != skill[end - 1])
end--;
}
if ((end-1 == 0) && tmp.empty())
{
answer++;
end = skill.length();
}
else if ((end - 1) != 0 && tmp.empty())
{
end = skill.length();
answer++;
}
else
{
end = skill.length();
while (!tmp.empty())
tmp.pop();
}
}
*/