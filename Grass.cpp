#include"Grass.h"

Grass::Grass(int posY, int posX,int age) {
	this->strength = 0;
	this->initiative = 0;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "Grass";
}
Grass::~Grass() {}

void Grass::drawing()
{
	cout << "#";
}
void Grass::newOrganism(Organism*** map, int posY, int posX) {
	map[posY][posX] = new Grass(posY, posX,0);
}