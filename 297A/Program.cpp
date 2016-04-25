#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

int main()
{
	std::string a, b;
	std::cin >> a >> b;

	int countA = 0, countB = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '1')
			countA++;
	}

	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == '1')
			countB++;
	}

	if (countA % 2 > 0)
		countA++;

	std::cout << (countA >= countB ? "YES" : "NO") << std::endl;

	return 0;
}