#pragma once
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<Windows.h>
#include<conio.h>
#include<fstream>


using namespace std;

enum DIRECTIONS {
	UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3
};

enum SIZES {
	HEIGHT=15,WIDTH=15};

enum KEYS {
	ARROWUP=72,
	ARROWLEFT=75,
	ARROWRIGHT=77,	
	ARROWDOWN=80,
	SPECIAL=32,
	SAVE = 83,
	LOAD = 76
};

enum SPIECES {
	HUMAN=10,
	ANTELOPE=1,
	BELLADONNA=2,
	FOX=3,
	GRASS=4,
	GUARANA=5,
	SHEEP=6,
	SOSNOWSKYHOGWEED=7,
	SOWTHISTLE=8,
	TURTLE=9,
	WOLF=0
};