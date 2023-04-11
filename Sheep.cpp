#include"Sheep.h"

Sheep::Sheep(int posY, int posX, int strength, int age) {
	this->strength = strength;
	this->initiative = 4;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "Sheep";
}
Sheep::~Sheep(){}
void Sheep::drawing()
{
	cout << "S";
}

void Sheep::newOrganism(Organism*** map, int posY, int posX) {
	map[posY][posX] = new Sheep(posY, posX,4,0);
}