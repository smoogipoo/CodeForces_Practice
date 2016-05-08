#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define PI 3.1415926535897932384726

int main()
{
	ll x1, y1, r1;
	ll x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	if (r1 > r2)
	{
		swap(r1, r2);
		swap(x1, x2);
		swap(y1, y2);
	}

	ld d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

	ld area;

	if (d < r2 - r1 + 1e-8)
		area = PI * r1 * r1;
	else if (d >= r1 + r2)
		area = 0;
	else
	{
		ld a1 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
		ld a2 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));

		ld s1 = a1 * r2 * r2;
		ld s2 = a2 * r1 * r1;

		ld t1 = r2 * r2 * sin(a1) * cos(a1);
		ld t2 = r1 * r1 * sin(a2) * cos(a2);

		area = s1 - t1 + s2 - t2;
	}

	cout.precision(17);
	cout << area << endl;
}