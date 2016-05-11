#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mii;

int main()
{
	int n;
	cin >> n;

	stringstream ss;

	for (int i = 1; i <= 1000; i++)
		ss << i;

	cout << ss.str()[n - 1] << endl;
}