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

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	b -= a;

	if (c == 0)
	{
		if (b == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	else if (b % c == 0)
	{
		if (b < 0 && c > 0 || b > 0 && c < 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
}