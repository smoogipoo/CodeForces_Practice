#include <bits/stdc++.h>
using namespace std;

int main()
{
	int digits;
	cin >> digits;

	string result;
	if (digits % 2 != 0)
	{
		// We need one 3
		for (int i = 0; i < 3; i++)
		{
			char c;
			cin >> c;
			result += c;

			digits--;
		}
	}

	while (digits > 0)
	{
		if (result != "")
			result += "-";
		for (int i = 0; i < 2; i++)
		{
			char c;
			cin >> c;
			result += c;

			digits--;
		}		
	}

	cout << result << endl;
}