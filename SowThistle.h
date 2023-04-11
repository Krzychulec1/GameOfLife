#pragma once

#include"Plant.h"

class SowThistle :public Plant {
public:
	void drawing() override;
	SowThistle(int posY, int posX,int age);
	void action(Organism*** map, string& comment) override;
	void newOrganism(Organism*** map, int posY, int posX) override;
	~SowThistle();
};