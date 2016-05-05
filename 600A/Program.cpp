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
	std::string sequence;
	std::cin >> sequence;

	std::vector<std::string> aValues;
	std::vector<std::string> bValues;
	std::string accum;
	bool isNumeric = true;
	bool first = true;
	for (int i = 0; i < sequence.size(); i++)
	{
		if (sequence[i] == ',' || sequence[i] == ';')
		{
			if (isNumeric && accum.size() > 0)
				aValues.push_back(accum);
			else
				bValues.push_back(accum);

			// Reset
			accum = "";
			first = true;
			isNumeric = true;

			continue;
		}

		if (first && sequence[i] == '0' && i < sequence.size() - 1 && sequence[i + 1] != ';' && sequence[i + 1] != ',')
			isNumeric = false;
		first = false;

		if (sequence[i] < '0' || sequence[i] > '9')
			isNumeric = false;

		accum += sequence[i];
	}

	if (isNumeric && accum.size() > 0)
		aValues.push_back(accum);
	else
		bValues.push_back(accum);

	std::string aString;
	std::string bString;

	if (aValues.size() == 0)
		aString = "-";
	else
	{
		aString = "\"";
		for (int i = 0; i < aValues.size(); i++)
		{
			if (i > 0)
				aString += ",";
			aString += aValues[i];
		}

		aString += "\"";
	}

	if (bValues.size() == 0)
		bString = "-";
	else
	{
		bString = "\"";
		for (int i = 0; i < bValues.size(); i++)
		{
			if (i > 0)
				bString += ",";
			bString += bValues[i];
		}

		bString += "\"";
	}

	std::cout << aString << '\n' << bString << std::endl;

	return 0;
}