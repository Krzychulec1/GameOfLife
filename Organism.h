#pragma once

#include <iostream>
#include <string>
#include"Definitions.h"

using namespace std;

class Organism {
protected:
	int strength, initiative,age;
	string name;
	int posY, posX;
	int moved = 0;
public:
	virtual void collision(Organism*** map,int posY,int posX,int newposY,int newposX,string &comment)=0;
	virtual void action(Organism*** map, string& comment)=0;
	virtual void moving(Organism*** map, int distance, string& comment) = 0;
	virtual void newOrganism(Organism*** map,int posY,int posX)=0;
	virtual void multiplication(Organism*** map, int posY, int posX, string& comment) = 0;
	virtual void drawing()=0;
	virtual int getStrength()=0;
	virtual int getAge()=0;
	virtual int getMoved() = 0;
	virtual int getInitiative() = 0;
	virtual string getName() = 0;
	virtual void changeMoved() = 0;
	virtual void changeAge() = 0;
	virtual void changeStrength() = 0;
	virtual void changeposY(int newposY) = 0;
	virtual void changeposX(int newposX) = 0;
	Organism();
	Organism(int posY,int posX);
	~Organism();
};