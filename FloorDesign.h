/*
 * floor.h
 *
 *  Created on: Nov 30, 2017
 *      Author: Alex Jasper
 */

#ifndef FLOOR_H_
#define FLOOR_H_





#endif /* FLOOR_H_ */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "CombatSystem.cpp"
#include <climits>
using namespace::std;

class Floor {
private:
	int level;
	Player* hero;

public:
	Floor(int level, Player* hero);
	bool run();
	bool runShop();
	void runStairs();
	bool runMonster();
	void runLoot();
	void runNothing();
	bool runBoss();
	int getLevel();

};
