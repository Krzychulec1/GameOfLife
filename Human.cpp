#include"Human.h"

Human::Human(World* world,int posY, int posX , int strength, int age,int cooldown) {
	this->strength = strength;
	this->initiative = 4;
	this->age = age;
	this->posY = posY;
	this->posX = posX;
	this->name = "Human";
	this->world = world;
	this->cooldown = cooldown;
}
Human::~Human() {}

void Human::newOrganism(Organism*** map, int posY, int posX) {}

void Human::purification(Organism*** map,string& comment) {
	if (posY - 1 >= 0)
	{
		if (map[posY - 1][posX] != NULL)
		{
			comment += "PURIFICATING " + map[posY - 1][posX]->getName() + '\n';
			map[posY - 1][posX] = NULL;
		}
	}
	if (posY + 1 <HEIGHT)
	{
		if (map[posY + 1][posX] != NULL) {
			comment += "PURIFICATING " + map[posY + 1][posX]->getName() + '\n';
			map[posY + 1][posX] = NULL;
		}
	}
	if (posX - 1 >= 0)
	{
		if (map[posY][posX - 1]!=NULL) {
			comment += "PURIFICATING " + map[posY][posX - 1]->getName() + '\n';
			map[posY][posX - 1] = NULL;
		}
	}
	if (posX+ 1 <WIDTH)
	{
		if (map[posY][posX + 1]!=NULL) {
			comment += "PURIFICATING " + map[posY][posX + 1]->getName() + '\n';
			map[posY][posX + 1] = NULL;
		}
	}
}

int Human::pickingDirection(Organism*** map, string& comment) {
	while (true)
	{
		int command = _getch();
		if (command == ARROWUP) {
			if (posY - 1 >= 0)
				return UP;
		}
		else if (command == ARROWDOWN) {
			if (posY + 1 < HEIGHT)
				return DOWN;
		}
		else if (command == ARROWLEFT) {
			if (posX - 1 >= 0)
				return LEFT;
		}
		else if (command == ARROWRIGHT) {
			if (posX + 1 < WIDTH)
				return RIGHT;
		}
		else if (command == SPECIAL) {
			if (cooldown <= 0)
			{
				cooldown = 10;
				comment += "Special activity activated \n";
			}
			if (cooldown >= 0 && cooldown <= 5) {
				comment += "Special activity is on cooldown \n";
			}
		}
		else if (command == SAVE) {
			world->save(cooldown);
			return SAVE;
		}
	}
}

void Human::moving(Organism*** map, int distance, string& comment)
{
	int newposY = posY;
	int newposX = posX;
	int move = 0;
	int load = 0;
	int direction = pickingDirection(map, comment);
	if (direction == LEFT && posX - distance >= 0) {
		newposX -= distance;
	}
	else if (direction == RIGHT && posX + distance < WIDTH) {
		newposX += distance;
	}
	else if (direction == UP && posY - distance >= 0) {
		newposY -= distance;
	}
	else if (direction == DOWN && posY + distance < HEIGHT) {
		newposY += distance;
	}
	else if (direction == SPECIAL) {
		move = 1;
	}
	else if (direction == SAVE) {
		move = 1;
	}
	if (move == 0) {
		if (map[newposY][newposX] != NULL)
		{
				map[newposY][newposX]->collision(map, posY, posX, newposY, newposX, comment);
		}
		else
		{
			map[newposY][newposX] = map[posY][posX];
			map[posY][posX] = NULL;
			changeposY(newposY);
			changeposX(newposX);
		}
		if (cooldown > 5)
		{
			purification(map, comment);
			cooldown--;
		}
		if (cooldown >= 0 && cooldown <= 5)
		{
			cooldown--;
		}
		this->moved = 1;
	}
	this->moved = 1;
}

void Human::drawing()
{
	cout << "X";
}