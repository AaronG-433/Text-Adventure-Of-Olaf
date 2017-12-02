
/*
 * FloorDesign.h
 *
 *  Created on: Nov 30, 2017
 *      Author: Owner
 */

#include <cstdlib>
#include <iostream>
//#include "CombatSystem.cpp"
//#include "CharacterCreation.cpp"
#include "MonsterGeneration.cpp"

class Floor {
private:
	int level;
	//Character hero;

public:
	Floor(int level);
	int getLevel();		//added getLevel() for monsterGeneration
	bool run();
	bool runShop();
	void runStairs();
	bool runMonster();
	void runLoot();
	void runNothing();
	bool runBoss();

};
