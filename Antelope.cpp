#include"Antelope.h"

Antelope::Antelope(int posY, int posX, int strength, int age) {
	this->strength = strength;
	this->initiative = 4;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "Antelope";
}
Antelope::~Antelope() {}

void Antelope::action(Organism*** map, string& comment)
{
	moving(map, 2,comment);
}

void Antelope::collision(Organism*** map, int attackerposY, int attackerposX, int posY, int posX, string& comment) {
	if (map[attackerposY][attackerposX]->getStrength() >= getStrength())
	{
		if (rand() % 2 == 0) {
			comment += map[attackerposY][attackerposX]->getName() + " kills " + map[posY][posX]->getName() + '\n';
			map[posY][posX] = NULL;
			map[posY][posX] = map[attackerposY][attackerposX];
			map[attackerposY][attackerposX] = NULL;
			map[posY][posX]->changeposX(posX);
			map[posY][posX]->changeposY(posY);
		}
		else
		{
			comment += "Antelope escapes " + '\n';
			moving(map, 2, comment);
			map[posY][posX] = NULL;
			map[posY][posX] = map[attackerposY][attackerposX];
			map[attackerposY][attackerposX] = NULL;
			map[posY][posX]->changeposX(posX);
			map[posY][posX]->changeposY(posY);
		}
	}
	else
	{
		comment += map[posY][posX]->getName() + " kills " + map[attackerposY][attackerposX]->getName() + '\n';
		map[attackerposY][attackerposX] = NULL;
	}
}

void Antelope::drawing()
{
	cout << "A";
}

void Antelope::newOrganism(Organism*** map, int posY, int posX) {
	map[posY][posX] = new Antelope(posY, posX,4,0);
}
