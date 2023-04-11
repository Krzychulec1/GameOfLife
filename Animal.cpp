#include"Animal.h"

Animal::Animal() {}

Animal::Animal(int posY, int posX, int strength, int age) {}

Animal::~Animal(){}

int Animal::getAge()
{
	return age;
}

int Animal::getStrength()
{
	return strength;
}

int Animal::getMoved()
{
	return moved;
}

int Animal::getInitiative()
{
	return initiative;
}

string Animal::getName()
{
	return name;
}

void Animal::changeMoved()
{
	if (moved == 0)
		moved = 1;
	else
		moved = 0;
}
void Animal::changeAge()
{
	this->age++;
}

void Animal::changeposY(int newposY)
{
	this->posY = newposY;
}

void Animal::changeposX(int newposX)
{
	this->posX = newposX;
}

void Animal::changeStrength()
{
	this->strength += 3;
}

void Animal::action(Organism*** map, string& comment) {
	moving(map,1,comment);
}

void Animal::multiplication(Organism*** map, int posY, int posX, string& comment) {
	int newposY = posY;
	int newposX = posX;
	int direction = rand() % 4;
	newposY = posY;
	newposX = posX;
	if (direction == LEFT && posX - 1 >= 0) {
		newposX -= 1;
	}
	else if (direction == RIGHT && posX + 1 < WIDTH) {
		newposX += 1;
	}
	else if (direction == UP && posY - 1 >= 0) {
		newposY -= 1;
	}
	else if (direction == DOWN && posY + 1 < HEIGHT) {
		newposY += 1;
	}
	if (map[newposY][newposX] == NULL)
	{
		comment += getName() + " breeds" + '\n';
		newOrganism(map, newposY, newposX);
		map[newposY][newposX]->changeMoved();
	}
}

void Animal::moving(Organism*** map, int distance, string& comment)
{
	int newposY = posY;
	int newposX = posX;
	int move = 0;
	while (move == 0)
	{
		int direction = rand() % 4;
		if (direction == LEFT && posX-distance >= 0) {
			newposX -= distance;
			move = 1;
		}
		else if (direction == RIGHT && posX + distance < WIDTH) {
			newposX += distance;
			move = 1;
		}
		else if (direction == UP && posY-distance >= 0) {
			newposY -= distance;
			move = 1;
		}
		else if (direction == DOWN && posY + distance < HEIGHT) {
			newposY += distance;
			move = 1;
		}
	}
	if (map[newposY][newposX] != NULL)
	{
		if (map[newposY][newposX]->getName() == getName())
		{
			map[newposY][newposX]->multiplication(map, newposY, newposX,comment);
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

void Animal::collision(Organism*** map, int attackerposY, int attackerposX, int posY, int posX, string& comment) {
	if (map[attackerposY][attackerposX]->getStrength() >= getStrength())
	{
		comment += map[attackerposY][attackerposX]->getName() + " kills " + map[posY][posX]->getName() + '\n';
		map[posY][posX] = NULL;
		map[posY][posX] = map[attackerposY][attackerposX];
		map[attackerposY][attackerposX] = NULL;
		map[posY][posX]->changeposX(posX);
		map[posY][posX]->changeposY(posY);
	}
	else
	{
		comment += map[posY][posX]->getName() + " kills " + map[attackerposY][attackerposX]->getName() + '\n';
		map[attackerposY][attackerposX] = NULL;
	}
}

