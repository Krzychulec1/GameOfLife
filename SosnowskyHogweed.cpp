#include"SosnowskyHogweed.h"

SosnowskyHogweed::SosnowskyHogweed(int posY, int posX,int age) {
	this->strength = 10;
	this->initiative = 0;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "SosnowskyHogweed";
}
SosnowskyHogweed::~SosnowskyHogweed() {}

void SosnowskyHogweed::drawing()
{
	cout << "!";
}
void SosnowskyHogweed::newOrganism(Organism*** map, int posY, int posX) {
	map[posY][posX] = new SosnowskyHogweed(posY, posX,0);
}
void SosnowskyHogweed::action(Organism*** map, string& comment){
	specialAction(map, comment);
	int probability = rand() % 100;
	if (probability == 1)
	{
		multiplication(map, posY, posX, comment);
	}
}

void SosnowskyHogweed::specialAction(Organism*** map, string& comment) {
	if (posY + 1 < HEIGHT)
	{
		if (map[posY + 1][posX] != NULL && map[posY + 1][posX]->getInitiative() != 0)
		{
			comment += getName() + " kills " + map[posY + 1][posX]->getName() + '\n';
			map[posY + 1][posX] = NULL;
		}
	}
	if (posY - 1 >= 0)
	{
		if (map[posY - 1][posX] != NULL && map[posY - 1][posX]->getInitiative() != 0)
		{
			comment += getName() + " kills " + map[posY - 1][posX]->getName() + '\n';
			map[posY - 1][posX] = NULL;
		}
	}
	if (posX + 1 < WIDTH)
	{
		if (map[posY][posX + 1] != NULL && map[posY][posX + 1]->getInitiative() != 0)
		{
			comment += getName() + " kills " + map[posY][posX+1]->getName() + '\n';
			map[posY][posX+1] = NULL;
		}
	}
	if (posX - 1 >= 0)
	{
		if (map[posY][posX - 1] != NULL && map[posY][posX - 1]->getInitiative() != 0)
		{
			comment += getName() + " kills " + map[posY][posX-1]->getName() + '\n';
			map[posY][posX-1] = NULL;
		}
	}
}
