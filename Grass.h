#pragma once

#include"Plant.h"

class Grass :public Plant {
public:
	void drawing() override;
	void newOrganism(Organism*** map, int posY, int posX) override;
	Grass( int posY, int posX,int age);
	~Grass();
};