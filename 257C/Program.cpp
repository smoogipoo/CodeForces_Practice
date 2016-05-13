#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ld> vld;

const ld PI = 3.1415926535897932384626;

int main()
{
	int n;
	cin >> n;

	vld angles;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		angles.push_back(atan2l(y, x) * 180.0 / PI);
	}

	sort(angles.begin(), angles.end());
	
	ld angle = angles[n - 1] - angles[0];
	for (int i = 1; i < n; i++)
		angle = min(angle, angles[i - 1] + 360 - angles[i]);

	cout.precision(12);
	cout << fixed << angle << endl;
}