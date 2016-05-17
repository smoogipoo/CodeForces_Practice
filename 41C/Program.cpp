#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef long long ll;

int main()
{
	string s;
	cin >> s;

	string newStr;

	bool atWritten = false;
	for (int i = 0; i < s.size(); i++)
	{
		bool inAtBounds = i > 0 && i < s.size() - 2;
		bool inDotBounds = i > 0 && i < s.size() - 3;

		if (inAtBounds && !atWritten && s[i] == 'a' && s[i + 1] == 't')
		{
			newStr += '@';
			atWritten = true;
			i += 1;

			goto next;
		}

		if (inDotBounds && s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't')
		{
			newStr += '.';
			i += 2;

			goto next;
		}

		newStr += s[i];

next:;
	}

	cout << newStr << endl;
}