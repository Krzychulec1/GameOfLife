#pragma once

#include"Plant.h"

class SosnowskyHogweed :public Plant {
public:
	void drawing() override;
	SosnowskyHogweed(int posY, int posX,int age);
	void action(Organism*** map, string& comment);
	void specialAction(Organism*** map, string& comment);
	void newOrganism(Organism*** map, int posY, int posX) override;
	~SosnowskyHogweed();
};
