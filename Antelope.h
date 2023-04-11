#pragma once

#include"Animal.h"

class Antelope:public Animal {
public:
	void drawing() override;
	Antelope(int posY, int posX, int strength, int age);
	void collision(Organism*** map, int posY, int posX, int newposY, int newposX, string& comment) override;
	void action(Organism*** map, string& comment) override;
	void newOrganism(Organism*** map, int posY, int posX) override;
	~Antelope();
};