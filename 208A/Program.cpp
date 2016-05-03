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

#define vi std::vector<int>

typedef long long ll;

int main()
{
	std::string str;
	std::cin >> str;

	std::stringstream ss;

	bool firstWord = true;
	bool lastWub = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (i > str.size() - 3 || str[i] != 'W')
		{
			ss << str[i];
			firstWord = false;
			lastWub = false;
			continue;
		}

		// We have a W
		if (str[i + 1] == 'U' && str[i + 2] == 'B')
		{
			i += 2;
			if (!firstWord & !lastWub)
				ss << ' ';
			lastWub = true;
		}
		else
		{
			ss << str[i];
			firstWord = false;
			lastWub = false;
		}
	}

	std::cout << ss.str() << std::endl;

	return 0;
}