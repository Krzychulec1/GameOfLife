#pragma once

#include"Animal.h"

class Fox :public Animal {
public:
	void drawing() override;
	int getPosX();
	int getPosY();
	void moving(Organism*** map, int distance, string& comment) override;
	void newOrganism(Organism*** map, int posY, int posX) override;
	Fox(int posY, int posX, int strength, int age);
	~Fox();
};