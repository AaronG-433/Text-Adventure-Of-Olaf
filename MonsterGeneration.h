#ifndef monster_H
#define monster_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 *monster.h
 *Summary: Monster/Boss Generation method: Be able to return a monster/boss when called.
 *Include a variety of monsters to be encountered with various base stats.
 *Author: Johnny Li
 *COP 3503 Section Number: 128D
 */

/*
 * Monster class - create a randomly generated monster.
 */
class monster{
//Monster information
private:
	string name;
	int hp;
	int damage;
	int defense;
	int loot;

public:
	monster();
	string monsterGeneration();
	int HP();
	int DAMAGE();
	int DEFENSE();
	int LOOT();
	void boss();
};

//Monster Constructor
monster::monster(){
	name =monsterGeneration();
	hp =HP();
	damage =DAMAGE();
	defense =DEFENSE();
	loot =LOOT();
}


void monster::boss()
#endif

