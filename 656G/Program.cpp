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

#define vi std::vector<int>

typedef long long ll;

int main()
{
	int f, i, t;
	std::cin >> f >> i >> t;

	vi scores;
	scores.resize(i);

	for (int i = 0; i < f; i++)
	{
		std::string s;
		std::cin >> s;
		for (int j = 0; j < s.size(); j++)
			scores[j] += (s[j] == 'Y' ? 1 : 0);
	}

	int countThresh = 0;
	for (int j = 0; j < i; j++)
		countThresh += scores[j] >= t;

	std::cout << countThresh << std::endl;

	return 0;
}