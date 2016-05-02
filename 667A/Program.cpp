#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>

const double PI = 3.14159265358979;

double getVolume(int d, int h)
{
	return PI * d * d / 4.0;
}

int main()
{
	int d, h, v, e;
	std::cin >> d >> h >> v >> e;

	double t = (-PI * d * d * h / 4) / (PI * d * d * e / 4 - v);

	if (t < 0 || t > 1e4)
		std::cout << "NO" << std::endl;
	else
		std::cout << "YES\n" << std::setprecision(12) << t << std::endl;

	return 0;
}