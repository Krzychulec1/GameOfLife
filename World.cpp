#include"World.h"
#include"Wolf.h"
#include"Sheep.h"
#include"Fox.h"
#include"Turtle.h"
#include"Antelope.h"
#include"Belladonna.h"
#include"Grass.h"
#include"Guarana.h"
#include"SosnowskyHogweed.h"
#include"SowThistle.h"
#include"Human.h"
#include"Definitions.h"

World::World(int N,int M){

	newMap(N, M);
	int numberOfOrganisms;
	int ifrandomly;
	int turn = 0;
	int loading = 0;
	cout << "If you want to load the game click 1, if you want to start new game click any other button" << endl;
	cin >> loading;
	if (loading == 1) {
		load();
	}
	else {
		cout << "Input number of organisms" << endl;
		cin >> numberOfOrganisms;
		cout << "If You want to pick spieces click 1 else click any other key" << endl;
		cin >> ifrandomly;
		map[HEIGHT / 2][WIDTH / 2] = new Human(this, HEIGHT / 2, WIDTH / 2, 5, 0, 0);
		if (ifrandomly == 1)
		{
			cout << "Press 0 to spawn Wolf" << endl;
			cout << "Press 1 to spawn Antelope" << endl;
			cout << "Press 2 to spawn Belladonna" << endl;
			cout << "Press 3 to spawn Fox" << endl;
			cout << "Press 4 to spawn Grass" << endl;
			cout << "Press 5 to spawn Guarana" << endl;
			cout << "Press 6 to spawn Sheep" << endl;
			cout << "Press 7 to spawn Sosnowsky's Hogweed" << endl;
			cout << "Press 8 to spawn Sow Thistle" << endl;
			cout << "Press 9 to spawn Turtle" << endl;
			cout << "pick spieces:" << endl;
			for (int i = 0; i < numberOfOrganisms; i++)
			{
				char spieces = _getch();
				spieces = spieces - '0';
				addOrganism(map, spieces);
			}
		}
		else
		{
			for (int i = 0; i < numberOfOrganisms; i++) {
				int spieces = rand() % 10 + 1;
				addOrganism(map, spieces);
			}
		}
	}
	drawWorld();
	while (true)
	{
		makeTurn(map);
		resetMove(map);
	}
}
void World::addOrganism(Organism*** map, int species)
{
	srand(time(NULL));
	int y = rand() % HEIGHT;
	int x = rand() % WIDTH;
	while (map[y][x]!=NULL)
	{
		y = rand() % HEIGHT;
		x = rand() % WIDTH;
	}
	if (species == ANTELOPE)
	{
		map[y][x] = new Antelope( y, x,4,0);
	}
	else if (species == BELLADONNA)
	{
		map[y][x] = new Belladonna(y, x,0);
	}
	else if (species == FOX)
	{
		map[y][x] = new Fox( y, x,3,0);
	}
	else if (species == GRASS)
	{
		map[y][x] = new Grass(y, x,0);
	}
	else if (species == GUARANA)
	{
		map[y][x] = new Guarana(y, x,0);
	}
	else if (species == SHEEP)
	{
		map[y][x] = new Sheep( y, x,4,0);
	}
	else if (species == SOSNOWSKYHOGWEED)
	{
		map[y][x] = new SosnowskyHogweed( y, x,0);
	}
	else if (species == SOWTHISTLE)
	{
		map[y][x] = new SowThistle( y, x,0);
	}
	else if (species ==TURTLE)
	{
		map[y][x] = new Turtle(y, x,2,0);
	}
	else if (species == WOLF)
	{
		map[y][x] = new Wolf(y,x,9,0);
	}
}
void World::changeTurn() {
	turn++;
}

void World::newMap(int N,int M)
{
	map = new Organism**[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new Organism * [M];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] = NULL;
		}
	}
}

void World::makeTurn(Organism*** map) {
	comment = '\n';
	int human = 0;
	int animal = 0;
	int initiatives[5] = { 7,5,4,1,0 };
	for (int l = turn; l >= 0; l--)
	{
		for (int k = 0; k < 5; k++)
		{
			for (int i = 0; i < HEIGHT; i++)
			{
				for (int j = 0; j < WIDTH; j++)
				{
					if (map[i][j] != NULL)
					{
						if (map[i][j]->getAge() == l)
						{
							if (map[i][j]->getName() == "Human")
								human = 1;
							if (map[i][j] != NULL && map[i][j]->getName() != "Human")
								animal = 1;
							if (map[i][j]->getInitiative() == initiatives[k] && map[i][j]->getMoved() != 1)
							{
								map[i][j]->action(map, comment);
							}
						}
					}
				}
			}
		}
	}
	system("cls");
	drawWorld();
	if (human == 0)
	{
		cout << "YOU LOST" << endl;
		Sleep(10);
		exit(0);
	}
	else if (animal == 0)
	{
		cout << "YOU WON" << endl;
		Sleep(10);
		exit(0);
	}

}

void World::drawWorld(){
	cout << "Krzysztof Jeznach 188771" << endl;
	cout << "Turn number: " << turn << endl;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (map[i][j] == NULL)
				cout << "_";
			else
			{
				map[i][j]->drawing();
			}
		}
		cout << endl;
	}
	cout << comment;
}

void World::resetMove(Organism*** map)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (map[i][j] != NULL)
			{
				map[i][j]->changeMoved();
				map[i][j]->changeAge();
			}
		}
	}
	changeTurn();
}

void World::save(int s) {
	fstream save;
	system("cls");
	cout << "Give save name: ";
	string save_name;
	cin >> save_name;
	save.open(save_name, fstream::out);
	if (save.good()) {
		cout << "Save succesfuly created" << endl;
		Sleep(1500);
	}
	else {
		cout << "ERROR" << endl;
		Sleep(1500);
	}
	save << HEIGHT << " " << WIDTH << " " << turn << endl;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (map[i][j] == NULL) {
				save << "NULL" << " " << 0 << " " << 0 << " " << 0 << endl;
			}
			else if (map[i][j]->getName() == "Human") {
				save << map[i][j]->getName() << " " << map[i][j]->getAge() << " " << s << " " << map[i][j]->getStrength() << endl;
			}
			else {
				save << map[i][j]->getName() << " " << map[i][j]->getAge() << " " << 0 << " " << map[i][j]->getStrength() << endl;
			}
		}
	}
	save.close();
}

void World::setTurn(int t) {
	turn = t;
}

void World::load() {
	fstream save;
	system("cls");
	cout << "Give file name: ";
	string save_name;
	cin >> save_name;
	save.open(save_name, fstream::in);
	if (save.good()) {
		for (int i = 0; i < HEIGHT; i++) {
			delete[] map[i];
		}
		delete[] map;
		int width, height, turns;
		save >> height >> width >> turns;
		setTurn(turns);
		string spiece;
		int age, cooldown, strength;
		newMap(height,width);
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				save >> spiece >> age >> cooldown >> strength;
				if (spiece == "Wolf") {
					map[y][x] = new Wolf(y,x, strength, age);
				}
				else if (spiece == "Sheep") {
					map[y][x] = new Sheep(y,x, strength, age);
				}
				else if (spiece == "Fox") {
					map[y][x] = new Fox(y, x, strength, age);
				}
				else if (spiece == "Turtle") {
					map[y][x] = new Turtle(y, x, strength, age);
				}
				else if (spiece == "Antelope") {
					map[y][x] = new Antelope(y, x, strength, age);
				}
				else if (spiece == "Grass") {
					map[y][x] = new Grass(y, x, age);
				}
				else if (spiece == "SowThistle") {
					map[y][x] = new SowThistle(y, x, age);
				}
				else if (spiece == "Guarana") {
					map[y][x] = new Guarana(y, x, age);
				}
				else if (spiece == "Belladonna") {
					map[y][x] = new Belladonna(y, x, age);
				}
				else if (spiece == "SosnowskyHogweed") {
					map[y][x] = new SosnowskyHogweed(y, x, age);
				}
				else if (spiece == "Human") {
					map[y][x] = new Human(this,y,x, strength, age,cooldown);
				}
				else {
					map[y][x] = NULL;
				}
			}
		}
	}
	else {
		cout << "ERROR" << endl;
		Sleep(1500);
	} 
	save.close();
	system("cls");
}



World::~World(){}



