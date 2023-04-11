#include"Belladonna.h"

Belladonna::Belladonna(int posY, int posX,int age) {
	this->strength = 99;
	this->initiative = 0;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "Belladonna";
}
Belladonna::~Belladonna() {}

void Belladonna::collision(Organism*** map, int attackerposY, int attackerposX, int posY, int posX, string& comment) {
	if (map[attackerposY][attackerposX]->getInitiative() !=0) {
		comment += map[attackerposY][attackerposX]->getName() + "eats Belladonna" + '\n';
		comment += "Belladonna kills " + map[attackerposY][attackerposX]->getName() + '\n';
		map[posY][posX] = NULL;
		map[attackerposY][attackerposX] = NULL;
	}
}

void Belladonna::drawing()
{
	cout << "\\";
}
void Belladonna::newOrganism(Organism*** map, int posY, int posX) {
	map[posY][posX] = new Belladonna(posY, posX,0);
}