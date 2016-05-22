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

/*
q1 a q2
b q3 c
q4 d q5

q3 = any from 1-n so we must multiply result by this (*n)

q1 + b = q2 + c
q2 = q1 + b - c

q1 + a = q4 + d
q4 = q1 + a - d

a + q2 = d + q5
q5 = a + q2 - d
*/

int main()
{
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	ll count = 0;

	for (int q1 = 1; q1 <= n; q1++)
	{
		int q2 = q1 + b - c;
		int q4 = q1 + a - d;
		int q5 = a + q2 - d;

		if (q2 < 1 || q2 > n || q4 < 1 || q4 > n || q5 < 1 || q5 > n)
			continue;
		count++;
	}

	count *= n;

	cout << count << endl;
}