#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef long long ll;

int main()
{
	string a;
	string b;

	cin >> a >> b;

	if (a.size() != b.size())
	{
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[b.size() - 1 - i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
}