#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

struct Person
{
public:
	Person(char gender, int from, int to) : Gender(gender), From(from), To(to) { }

public:
	char Gender;
	int From;
	int To;
};

int main()
{
	int pCount;
	std::cin >> pCount;

	std::vector<Person> people;
	for (int i = 0; i < pCount; i++)
	{
		char gender;
		int from, to;
		std::cin >> gender >> from >> to;

		people.push_back(Person(gender, from, to));
	}

	int countMax = 0;
	for (int i = 1; i <= 366; i++)
	{
		int countMale = 0;
		int countFemale = 0;

		for (int j = 0; j < people.size(); j++)
		{
			if (people[j].From > i || people[j].To < i)
				continue;

			if (people[j].Gender == 'M')
				countMale++;
			else
				countFemale++;
		}

		int& min = countMale < countFemale ? countMale : countFemale;

		if (min * 2 > countMax)
			countMax = min * 2;
	}

	std::cout << countMax << std::endl;

	return 0;
}