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

struct Num
{
public:
	int value;
	int index;
};

struct NumSort
{
public:
	bool operator()(const Num& left, const Num& right)
	{
		return left.value > right.value;
	}
};

int main()
{
	int n;
	std::cin >> n;

	std::vector<Num> vec;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		
		vec.push_back({ tmp, i });
	}

	std::sort(vec.begin(), vec.end(), NumSort());

	std::vector<int> result;
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i + 1; j < vec.size() - 1; j++)
		{
			for (int k = vec.size() - 1; k > j; k--)
			{
				if (vec[i].value - vec[j].value - vec[k].value == 0)
				{
					result.push_back(vec[i].index + 1);
					result.push_back(vec[j].index + 1);
					result.push_back(vec[k].index + 1);
					goto found;
				}
			}
		}
	}

found:;

	if (result.size() == 0)
		std::cout << -1 << std::endl;
	else
		std::cout << result[0] << ' ' << result[1] << ' ' << result[2] << std::endl;

	return 0;
}