#pragma once

#include"Plant.h"

class Belladonna :public Plant {
public:
	void drawing() override;
	Belladonna( int posY, int posX,int age);
	void collision(Organism*** map, int posY, int posX, int newposY, int newposX, string& comment) override;
	void newOrganism(Organism*** map, int posY, int posX) override;
	~Belladonna();
};
