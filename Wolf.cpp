#include"Wolf.h"

Wolf::Wolf(int posY,int posX, int strength, int age){
	this->strength = strength;
	this->initiative = 5;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "Wolf";
}
Wolf::~Wolf(){}

void Wolf::newOrganism(Organism*** map, int posY, int posX) {
	map[posY][posX] = new Wolf(posY, posX,strength,age);
}

void Wolf::drawing()
{
	cout << "W";
}