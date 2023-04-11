#pragma once

#include"Animal.h"

class Human :public Animal {
protected:
	int cooldown = 0;
	World* world;
public:
	void drawing() override;
	Human(World* world,int posY, int posX, int strength, int age,int cooldown);
	int pickingDirection(Organism*** map, string& comment);
	void purification(Organism*** map, string& comment);
	void moving(Organism*** map, int distance, string& comment)override;
	void newOrganism(Organism*** map, int posY, int posX) override;
	~Human();
};