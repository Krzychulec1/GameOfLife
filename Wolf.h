#pragma once

#include"Animal.h"

class Wolf :public Animal {
public:
	void drawing() override;
	Wolf(int posY, int posX, int strength, int age);
	void newOrganism(Organism*** map,int posY,int posX) override;
	~Wolf();
};