#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef map<int, int> mi;

int main()
{
	int n;
	cin >> n;

	mi spitMap;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		int finalPos = a + b;
		spitMap[a] = finalPos;
	}

	bool yes = false;
	for (mi::iterator it = spitMap.begin(); it != spitMap.end(); it++)
	{
		auto other = spitMap.find(it->second);
		if (other == spitMap.end())
			continue;
		if (other->second == it->first)
		{
			yes = true;
			break;
		}
	}
	
	cout << (yes ? "YES" : "NO") << endl;
}