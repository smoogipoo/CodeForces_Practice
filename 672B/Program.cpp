#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mii;

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	vi counts(26, 0);
	for (int i = 0; i < n; i++)
		counts[s[i] - 'a']++;

	int uniqueAvailable = 0;
	int countToChange = 0;
	for (int i = 0; i < 26; i++)
	{
		if (counts[i] == 0)
			uniqueAvailable++;
		else if (counts[i] > 1)
			countToChange += (counts[i] - 1);
	}

	if (countToChange == 0)
		cout << 0 << endl;
	else if (countToChange > uniqueAvailable)
		cout << -1 << endl;
	else
		cout << countToChange << endl;
}