#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <functional>
#include <map>
#include <sstream>

typedef long long ll;

int main()
{
	int n, x;
	scanf("%d %d", &n, &x);

	std::vector<int> chapters;

	while (n-- > 0)
	{
		int c;
		scanf("%d", &c);

		chapters.push_back(c);
	}

	std::sort(chapters.begin(), chapters.end());

	ll result = 0;
	for (int i = 0; i < chapters.size(); i++)
	{
		result += chapters[i] * ll(x);
		x = std::max(1, x - 1);
	}

	std::cout << result << std::endl;

	return 0;
}