#pragma once
#include"Organism.h"
#include"World.h"

class Animal:public Organism {
public:
	void action(Organism*** map, string& comment) override;
	void collision(Organism*** map,int posY,int posX,int newposY,int newposX, string& comment) override;
	void moving(Organism*** map, int distance, string& comment)override;
	void multiplication(Organism*** map, int posY, int posX,string& comment) override;
	Animal();
	int getStrength() override;
	int getAge() override;
	int getMoved() override;
	int getInitiative()override;
	string getName() override;
	void changeMoved() override;
	void changeAge() override;
	void changeStrength()override;
	void changeposY(int newposY) override;
	void changeposX(int newposX) override;
	Animal(int posY,int posX,int strength,int age);
	~Animal();
};
