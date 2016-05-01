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

int main()
{
	int l1, r1, l2, r2;
	std::cin >> l1 >> r1 >> l2 >> r2;

	l1 -= 1;
	r1 -= 1;
	l2 -= 1;
	r2 -= 1;

	std::map<char, std::vector<int>> mci;

	std::vector<char> allChars;
	for (char c = 'a'; c <= 'z'; c++)
		allChars.push_back(c);
	for (char c = '0'; c <= '9'; c++)
		allChars.push_back(c);

	std::vector<long long> mod;
	std::vector<long long> remainder;

	mod.push_back(2);
	remainder.push_back(0);

	for (int i = 1; i < allChars.size(); i++)
	{
		mod.push_back(mod[i - 1] * 2);
		remainder.push_back(remainder[i - 1] * 2 + 1);
	}

	std::stringstream leftStream;
	std::stringstream rightStream;

	for (int i = l1; i <= r1; i++)
	{
		for (int j = 0; j < allChars.size(); j++)
		{
			if (i % mod[j] == remainder[j])
				leftStream << allChars[j];
		}
	}

	for (int i = l2; i <= r2; i++)
	{
		for (int j = 0; j < allChars.size(); j++)
		{
			if (i % mod[j] == remainder[j])
				rightStream << allChars[j];
		}
	}

	std::string left = leftStream.str();
	std::string right = rightStream.str();

	int length = 0;
	if (left.size() != 0 && right.size() != 0)
	{
		int* curr = new int[right.size()];
		int* prev = new int[right.size()];
		
		for (int i = 0; i < left.size(); i++)
		{
			for (int j = 0; j < right.size(); j++)
			{
				if (left[i] != right[j])
					curr[j] = 0;
				else
				{
					if (i == 0 || j == 0)
						curr[j] = 1;
					else
						curr[j] = 1 + prev[j - 1];

					if (length < curr[j])
						length = curr[j];
				}
			}

			int* swap = curr;
			curr = prev;
			prev = swap;
		}

		delete[] curr;
		delete[] prev;
	}

	std::cout << length << std::endl;

	return 0;
}