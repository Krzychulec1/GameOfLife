#include"Fox.h"

Fox::Fox(int posY, int posX, int strength, int age) {
	this->strength = strength;
	this->initiative = 7;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "Fox";
}
Fox::~Fox() {}

int Fox::getPosX() {
	return posX;
}

int Fox::getPosY() {
	return posY;
}

void Fox::drawing()
{
	cout << "F";
}
void Fox::newOrganism(Organism*** map, int posY, int posX) {
	map[posY][posX] = new Fox(posY, posX,3,0);
}

void Fox::moving(Organism*** map, int distance, string& comment) {
	int newposY = posY;
	int newposX = posX;
	int canmove = 0;
	int move = 0;
	int direction = rand() % 4;
	if (direction == LEFT && posX-1 >= 0) {
		newposX -= distance;
		move = 1;
	}
	else if (direction == RIGHT && posX + 1 < WIDTH) {
		newposX += distance;
		move = 1;
	}
	else if (direction == UP && posY-1 >= 0) {
		newposY -= distance;
		move = 1;
	}
	else if (direction == DOWN && posY + 1 < HEIGHT) {
		newposY += distance;
		move = 1;
	}
	if (map[newposY][newposX] != NULL)
	{
		if (this->strength > map[newposY][newposX]->getStrength())
		{
			canmove = 1;
		}
		else if (map[newposY][newposX]->getName() == getName())
		{
			canmove = 1;
		}
	}
	else
		canmove = 1;
	if (canmove == 1 && move==1)
	{
		if (map[newposY][newposX] != NULL)
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
		this->moved = 1;
	}
	this->moved = 1;
}