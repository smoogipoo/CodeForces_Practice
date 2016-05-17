#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef long long ll;

int main()
{
	int n;
	cin >> n;

	if (n <= 1)
	{
		cout << 0 << endl;
		return 0;
	}

	if (n == 2)
	{
		cout << 1 << endl;
		cout << 1 << ' ' << 2 << endl;
		return 0;
	}

	vs roads;

	int leftStart = 2;
	int leftEnd = (int)ceil(n / 2.0f);
	int rightStart = leftEnd + 1;
	int rightEnd = n;

	for (int i1 = leftStart; i1 <= leftEnd; i1++)
	{
		for (int i2 = rightStart; i2 <= rightEnd; i2++)
			roads.push_back(to_string(i1) + " " + to_string(i2));
	}

	for (int i = rightStart; i <= rightEnd; i++)
		roads.push_back(to_string(1) + " " + to_string(i));

	cout << roads.size() << endl;
	for (int i = 0; i < roads.size(); i++)
		cout << roads[i] << endl;
}