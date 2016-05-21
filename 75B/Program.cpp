#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vv;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef map<string, int> msi;
typedef map<string, msi> msmsi;
typedef map<int, int> mii;
typedef map<int, string> mis;
typedef long long ll;
typedef long double ld;

struct rel
{
	string name;
	int value;
};

struct relComparator
{
	bool operator()(const rel& first, const rel& second)
	{
		if (first.value == second.value)
			return first.name < second.name;
		return first.value > second.value;	
	}
};



void parse(string& name1, string& name2, string& type)
{
	bool firstNameRead = false;
	bool secondNameRead = false;
	bool typeRead = false;
	bool hasContinuation = false;

	string line;
	getline(cin, line);

	for (int i = 0; i < line.size(); i++)
	{
		char c = line[i];

		// Read X
		if (!firstNameRead)
		{
			if (c == ' ')
			{
				firstNameRead = true;
				continue;
			}

			name1 += c;
			continue;
		}

		// Read posted/commented/likes
		if (!typeRead)
		{
			if (c == ' ')
			{
				typeRead = true;
				hasContinuation = type != "likes";
				continue;
			}

			type += c;
			continue;
		}

		if (hasContinuation)
		{
			if (c == ' ')
			{
				hasContinuation = false;
				continue;
			}

			continue;
		}

		if (!secondNameRead)
		{
			if (c == '\'')
			{
				secondNameRead = true;
				break;
			}

			name2 += c;
			continue;
		}
	}
}

int main()
{
	string name;
	int exprCount;
	cin >> name >> exprCount;

	msmsi relations;

	string tmp;
	getline(cin, tmp);

	for (int i = 0; i < exprCount; i++)
	{
		string name1;
		string name2;
		string type;

		parse(name1, name2, type);

		if (name1 != name && name2 != name)
		{
			relations[name1][name2] += 0;
			relations[name2][name1] += 0;
			continue;
		}

		if (type == "posted")
		{
			relations[name1][name2] += 15;
			relations[name2][name1] += 15;
		}
		else if (type == "commented")
		{
			relations[name1][name2] += 10;
			relations[name2][name1] += 10;
		}
		else if (type == "likes")
		{
			relations[name1][name2] += 5;
			relations[name2][name1] += 5;
		}
	}

	msi reduction1;
	for (auto it = relations.begin(); it != relations.end(); it++)
	{
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			if (it2->second > reduction1[it->first])
				reduction1[it->first] = it2->second;
		}

		
	}

	vector<rel> reduction2;
	for (auto it = reduction1.begin(); it != reduction1.end(); it++)
	{
		rel newRel;
		newRel.name = it->first;
		newRel.value = it->second;

		reduction2.push_back(newRel);
	}


	sort(reduction2.begin(), reduction2.end(), relComparator());

	for (int i = 0; i < reduction2.size(); i++)
	{
		if (reduction2[i].name == name)
			continue;

		if (i > 0)
			cout << '\n';
		cout << reduction2[i].name;
	}

	cout << endl;
}