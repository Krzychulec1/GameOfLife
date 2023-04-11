#pragma once

#include"Animal.h"

class Turtle :public Animal {
public:
	void drawing() override;
	Turtle(int posY, int posX, int strength, int age);
	void collision(Organism*** map, int posY, int posX, int newposY, int newposX, string& comment) override;
	void action(Organism*** map, string& comment) override;
	void moving(Organism*** map, int distance, string& comment)override;
	void newOrganism(Organism*** map, int posY, int posX) override;
	~Turtle();
};