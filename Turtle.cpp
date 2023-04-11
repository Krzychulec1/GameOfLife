#include"Turtle.h"

Turtle::Turtle(int posY, int posX, int strength, int age) {
	this->strength = strength;
	this->initiative = 1;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "Turtle";
}
Turtle::~Turtle() {}
void Turtle::drawing()
{
	cout << "T";
}
void Turtle::newOrganism(Organism*** map, int posY, int posX) {
	map[posY][posX] = new Turtle(posY, posX,strength,age);
}
void Turtle::action(Organism*** map, string& comment) {
		moving(map, 1,comment);
}

void Turtle::moving(Organism*** map, int distance, string& comment) {
	int newposY = posY;
	int newposX = posX;
	int move = 0;
		int direction = rand() % 16;
		if (direction == LEFT && posX > 0) {
			newposX -= distance;
			move = 1;
		}
		else if (direction == RIGHT && posX + 1 < WIDTH) {
			newposX += distance;
			move = 1;
		}
		else if (direction == UP && posY > 0) {
			newposY -= distance;
			move = 1;
		}
		else if (direction == DOWN && posY + 1 < HEIGHT) {
			newposY += distance;
			move = 1;
		}
		if (move == 1) {
			if (map[newposY][newposX] != 0)
			{
				if (map[newposY][newposX]->getName() == getName())
				{
					map[newposY][newposX]->multiplication(map, newposY, newposX, comment);
				}
				else
				{
					map[newposY][newposX]->collision(map, posY, posX, newposY, newposX, comment);
				}
			}
			else
			{
				map[newposY][newposX] = map[posY][posX];
				map[posY][posX] = NULL;
				changeposY(newposY);
				changeposX(newposX);
			}
		}
	this->moved = 1;
}
void Turtle::collision(Organism*** map, int attackerposY, int attackerposX, int posY, int posX, string& comment) {
	if (map[attackerposY][attackerposX]->getStrength() >= 5) {
		if (map[attackerposY][attackerposX]->getStrength() >= getStrength())
		{
			comment += map[attackerposY][attackerposX]->getName() + " kills " + map[posY][posX]->getName() + '\n';
			map[posY][posX] = NULL;
			map[posY][posX] = map[attackerposY][attackerposX];
			map[attackerposY][attackerposX] = NULL;
			map[posY][posX]->changeposX(posX);
			map[posY][posX]->changeposY(posY);
		}
	}
	else
		comment += "Turtle reflects attack of " + map[attackerposY][attackerposX]->getName()+'\n';
}
