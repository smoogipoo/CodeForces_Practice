#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string guestName, hostName, pileName;
	std::cin >> guestName >> hostName >> pileName;

	std::vector<int> countOriginals;
	std::vector<int> countPile;

	countOriginals.resize(26);
	countPile.resize(26);

	for (int i = 0; i < guestName.size(); i++)
	{
		countOriginals[guestName[i] - 'A']++;
	}
	for (int i = 0; i < hostName.size(); i++)
		countOriginals[hostName[i] - 'A']++;
	for (int i = 0; i < pileName.size(); i++)
		countPile[pileName[i] - 'A']++;

	bool failed = false;
	for (int i = 0; i < 26; i++)
	{
		if (countOriginals[i] != countPile[i])
		{
			failed = true;
			break;
		}
	}

	std::cout << (failed ? "NO" : "YES") << std::endl;

	return 0;
}