#include"Guarana.h"

Guarana::Guarana(int posY, int posX,int age)
{
	this->strength = 0;
	this->initiative = 0;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "Guarana";
}
Guarana::~Guarana() {}

void Guarana::collision(Organism*** map, int attackerposY, int attackerposX, int posY, int posX, string& comment) {
	map[attackerposY][attackerposX]->changeStrength();
	comment += "Guarana strengthens " + map[attackerposY][attackerposX]->getName() + '\n';
	map[posY][posX] = NULL;
	map[posY][posX] = map[attackerposY][attackerposX];
	map[attackerposY][attackerposX] = NULL;
	map[posY][posX]->changeposX(posX);
	map[posY][posX]->changeposY(posY);
}

void Guarana::drawing()
{
	cout << "@";
}

void Guarana::newOrganism(Organism*** map, int posY, int posX) {
	map[posY][posX] = new Guarana(posY, posX,0);
}