#include"Plant.h"

Plant::Plant(){}

Plant::Plant(int posY, int posX,int age) {}

int Plant::getAge()
{
	return age;
}

int Plant::getStrength()
{
	return strength;
}

int Plant::getMoved()
{
	return moved;
}

string Plant::getName()
{
	return name;
}

void Plant::changeMoved()
{
	this->moved = 0;
}
void Plant::changeAge()
{
	this->age++;
}

void Plant::collision(Organism*** map, int attackerposY, int attackerposX, int posY, int posX, string& comment) {
	if (map[attackerposY][attackerposX]->getStrength() >= getStrength())
	{
		comment+=map[attackerposY][attackerposX]->getName()+ " eats " + map[posY][posX]->getName() + '\n';
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

void Plant::action(Organism*** map, string& comment)
{
	int probability = rand() % 24;
	if (probability == 1)
	{
		multiplication(map, posY, posX,comment);
	}
}

void Plant::multiplication(Organism*** map, int posY, int posX, string& comment) {
	int newposY = posY;
	int newposX = posX;
	int direction = rand() % 4;
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
		comment += "sowing " + getName() + '\n';
		newOrganism(map, newposY, newposX);
		map[newposY][newposX]->changeMoved();
	}
}

void Plant::moving(Organism*** map, int distance, string& comment){}

int Plant::getInitiative() {
	return initiative;
}

void Plant::changeStrength() {}

void Plant::changeposY(int newposY) {}

void Plant::changeposX(int newposX) {}

Plant::~Plant() {}