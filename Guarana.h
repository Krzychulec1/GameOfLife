#pragma once

#include"Plant.h"

class Guarana :public Plant {
public:
	void drawing() override;
	Guarana(int posY, int posX,int age);
	void collision(Organism*** map, int posY, int posX, int newposY, int newposX, string& comment)override;
	void newOrganism(Organism*** map, int posY, int posX) override;
	~Guarana();
};
