#pragma once

#include"Animal.h"

class Sheep :public Animal {
public:
	void drawing() override;
	Sheep(int posY, int posX,int strength,int age);
	void newOrganism(Organism*** map, int posY, int posX) override;
	~Sheep();
};