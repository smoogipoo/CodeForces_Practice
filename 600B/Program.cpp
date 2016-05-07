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

struct Item
{
	int Index;
	int Value;
};

struct ItemValueSorter
{
	bool operator()(const Item& a, const Item& b)
	{
		return a.Value < b.Value;
	}
};

struct ItemIndexSorter
{
	bool operator()(const Item& a, const Item& b)
	{
		return a.Index < b.Index;
	}
};

int main()
{
	vi a;
	std::vector<Item> b;

	int aCount, bCount;

	std::cin >> aCount >> bCount;

	for (int i = 0; i < aCount; i++)
	{
		int tmp;
		std::cin >> tmp;

		a.push_back(tmp);
	}

	for (int i = 0; i < bCount; i++)
	{
		Item item;
		item.Index = i;
		std::cin >> item.Value;

		b.push_back(item);
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end(), ItemValueSorter());

	std::vector<Item> countsGreater;

	int currentCount = 0;
	int currentAIndex = 0;
	for (int i = 0; i < bCount; i++)
	{
		while (currentAIndex < a.size() && a[currentAIndex] <= b[i].Value)
		{
			currentCount++;
			currentAIndex++;
		}

		Item item;
		item.Index = b[i].Index;
		item.Value = currentCount;

		countsGreater.push_back(item);
	}

	std::vector<int> finalCounts;
	finalCounts.resize(b.size());

	for (int i = 0; i < b.size(); i++)
		finalCounts[countsGreater[i].Index] = countsGreater[i].Value;
	
	for (int i = 0; i < b.size(); i++)
	{
		if (i > 0)
			std::cout << ' ';
		std::cout << finalCounts[i];
	}

	std::cout << std::endl;

	return 0;
}