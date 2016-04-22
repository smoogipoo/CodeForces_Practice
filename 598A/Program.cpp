#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

int main()
{
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		long long n;
		std::cin >> n;

		long long r = 1 + n;
		long long allSum = r * (int)(n / 2) + (int)(n % 2 == 0 ? 0 : r / 2);

		for (int q = 1; q <= n; q *= 2)
			allSum -= q * 2;
		
		std::cout << allSum << std::endl;
	}

	return 0;
}