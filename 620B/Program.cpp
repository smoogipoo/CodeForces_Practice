#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

int main()
{
	constexpr const int segmentMap[] =
	{
		6,
		2,
		5,
		5,
		4,
		5,
		6,
		3,
		7,
		6
	};

	int a, b;
	std::cin >> a >> b;

	long long countPrintedSegments = 0;
	for (; a <= b; a++)
	{
		int i = a;
		while (i > 0)
		{
			countPrintedSegments += segmentMap[i % 10];
			i /= 10;
		}
	}

	std::cout << countPrintedSegments << std::endl;

	return 0;
}