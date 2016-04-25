#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	
	int sum = 0;
	while (n > 1)
	{
		sum += n;

		// Find the smallest number of rows
		int smallestDivisor = n;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				smallestDivisor = i;
				break;
			}
		}

		// Take away all other pebbles except one row
		n = n / smallestDivisor;
	}

	std::cout << sum + 1 << std::endl;

	return 0;
}