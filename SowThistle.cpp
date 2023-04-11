#include"SowThistle.h"

SowThistle::SowThistle(int posY, int posX,int age) {
	this->strength = 0;
	this->initiative = 0;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "SowThistle";
}
SowThistle::~SowThistle() {}

void SowThistle::action(Organism*** map, string& comment) {
	int probability = rand() % 8;
	if (probability == 1)
	{
		multiplication(map, posY, posX, comment);
	}
}


void SowThistle::drawing()
{
	cout << "/";
}

void SowThistle::newOrganism(Organism*** map, int posY, int posX) {
	map[posY][posX] = new SowThistle(posY, posX,0);
}