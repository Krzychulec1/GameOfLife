#pragma once
#include"Definitions.h"
#include"Organism.h"

class World {
protected:
	string comment;
	int turn=0;
	Organism*** map;
public:
    World(int height,int width);
	~World();
	void save(int s);
	void load();
	void changeTurn();
	void setTurn(int t);
	void addOrganism(Organism*** map, int species);
	void newMap(int height, int width);
	void makeTurn(Organism*** map);
	void resetMove(Organism*** map);
	void drawWorld();
};