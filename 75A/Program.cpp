#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef long long ll;

ll removeZeroes(ll num)
{
	ll ret = 0;

	ll shift = 1;
	while (num > 0)
	{
		int next = num % 10;
		num /= 10;

		if (next == 0)
			continue;

		ret += next * shift;
		shift *= 10;
	}

	return ret;
}

int main()
{
	ll a, b;
	cin >> a >> b;

	ll c = a + b;

	ll nA = removeZeroes(a);
	ll nB = removeZeroes(b);
	ll nC = removeZeroes(c);

	cout << (nA + nB == nC ? "YES" : "NO") << endl;
}