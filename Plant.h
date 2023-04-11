#pragma once
#include"Organism.h"

class Plant :public Organism {
public:
	Plant();
	Plant(int posY, int posX,int age);
	void action(Organism*** map, string& comment) override;
	void collision(Organism*** map, int posY, int posX, int newposY, int newposX, string& comment) override;
	void moving(Organism*** map, int distance, string& comment) override;
	void multiplication(Organism*** map, int posY, int posX,string& comment) override;
	int getStrength() override;
	int getAge() override;
	int getMoved() override;
	int getInitiative() override;
	string getName() override;
	void changeMoved() override;
	void changeAge() override;
	void changeStrength()override;
	void changeposY(int newposY)override;
	void changeposX(int newposX) override;
	~Plant();
};