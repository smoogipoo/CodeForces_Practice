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
	int n;
	cin >> n;

	int frontIterator = 1;
	int backIterator = 0;

	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			cout << ' ';

		if (i % 2 == 0)
		{
			// From the back
			cout << n - backIterator++;
		}
		else
		{
			// From the front
			cout << frontIterator++;
		}
	}

	cout << endl;
}