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
#include <sstream>
#include <climits>

#define vi std::vector<int>

typedef long long ll;

int main()
{
	int n;
	std::cin >> n;

	int min = INT_MIN, max = INT_MAX;

	bool isValid = true;

	for (int i = 0; i < n; i++)
	{
		std::string comp;
		int val;
		char result;

		std::cin >> comp >> val >> result;

		if (!isValid)
			continue;

		if (comp == ">")
		{
			if (result == 'Y')
			{
				if (val >= max)
					isValid = false;
				else
					min = std::max(min, val + 1);
			}
			else
			{
				if (val < min)
					isValid = false;
				else
					max = std::min(max, val);
			}
		}
		else if (comp == ">=")
		{
			if (result == 'Y')
			{
				if (val > max)
					isValid = false;
				else
					min = std::max(min, val);
			}
			else
			{
				if (val <= min)
					isValid = false;
				else
					max = std::min(max, val - 1);
			}
		}
		else if (comp == "<")
		{
			if (result == 'Y')
			{
				if (val <= min)
					isValid = false;
				else
					max = std::min(max, val - 1);
			}
			else
			{
				if (val > max)
					isValid = false;
				else
					min = std::max(min, val);
			}
		}
		else if (comp == "<=")
		{
			if (result == 'Y')
			{
				if (val < min)
					isValid = false;
				else
					max = std::min(max, val);
			}
			else
			{
				if (val >= max)
					isValid = false;
				else
					min = std::max(min, val + 1);
			}
		}
	}

	if (!isValid || min > 2e9 || max < -2e9)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << std::min((int)2e9, std::max((int)-2e9, min)) << std::endl;

	return 0;
}