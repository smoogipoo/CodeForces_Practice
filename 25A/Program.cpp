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

	vi v;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;

		v.push_back(tmp);
	}

	int oddIndex = 0;
	int evenIndex = -1;
	int oddCount = 0;
	int evenCount = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] % 2 == 0)
		{
			evenIndex = i;
			evenCount++;
		}
		else
		{
			oddIndex = i;
			oddCount++;
		}
	}

	std::cout << (evenCount > oddCount ? oddIndex + 1 : evenIndex + 1) << std::endl;

	return 0;
}