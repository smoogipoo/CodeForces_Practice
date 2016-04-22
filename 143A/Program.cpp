#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
	int r1, r2, c1, c2, d1, d2;
	std::cin >> r1 >> r2
			 >> c1 >> c2
			 >> d1 >> d2;

	std::vector<int> d1Combinations;
	d1Combinations.resize(10);

	std::vector<int> d2Combinations;
	d2Combinations.resize(10);

	for (int i = 1; i <= 9; i++)
	{
		d1Combinations[i] = d2Combinations[i] = 0;

		int d1LeftOver = d1 - i;
		int d2LeftOver = d2 - i;
		if (d1LeftOver <= 9 && d1LeftOver != i)
			d1Combinations[i] = d1LeftOver;
		if (d2LeftOver <= 9 && d2LeftOver != i)
			d2Combinations[i] = d2LeftOver;
	}

	bool found = false;
	std::vector<int> result;
	result.resize(4);
	
	for (int i = 1; i <= 9; i++)
	{
		// Check if the combination exists
		if (d1Combinations[i] == 0)
			continue;

		for (int j = 1; j <= 9; j++)
		{
			// Check if the combination exists
			if (d2Combinations[j] == 0)
				continue;

			// If we have the same numbers as in the d1 diagonal, we can't use these numbers
			if (j == i || j == d1Combinations[i] || i == d2Combinations[j] || d2Combinations[j] == d1Combinations[i])
				continue;

			// If the columns don't add up, we can't use these numbers
			if (i + d2Combinations[j] != c1 || j + d1Combinations[i] != c2)
				continue;

			// If the rows don't add up, we can't use these numbers
			if (i + j != r1 || d2Combinations[j] + d1Combinations[i] != r2)
				continue;

			result[0] = i;
			result[1] = j;
			result[2] = d2Combinations[j];
			result[3] = d1Combinations[i];
			
			found = true;
			break;
		}

		if (found)
			break;
	}

	if (!found)
		std::cout << -1 << std::endl;
	else
	{
		printf("%d %d\n%d %d", result[0], result[1], result[2], result[3]);
		std::cout << std::endl;
	}

	return 0;
}