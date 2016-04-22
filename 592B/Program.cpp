#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
	long long dp[54322];
	dp[3] = 1;
	dp[4] = 4;
	
	for (int i = 5, counter = 5; i <= 54321; i++, counter += 2)
		dp[i] = dp[i - 1] + counter;

	int n;
	std::cin >> n;

	std::cout << dp[n] << std::endl;

	return 0;
}